#include <stdio.h>
#include <string.h>
#include "daisy_seed.h"
#include "daisysp.h"
#include "dev/oled_ssd130x.h"
#include "OledDisplayExtravaganza.h"
#include "Menus.h"

using namespace daisy;
using namespace daisysp;


Menus                                  synthmenu;
DaisySeed                              hw;
OledDisplayExtravaganza                screen;
const int                              height = screen.Height();
const int                              width  = screen.Width();
const int                              poly   = 10;
Menus::oscVoice                        osc[poly];
Line                                   line[poly];
Adsr                                   env[poly];
bool                                   gate[poly];
MidiHandler<MidiUartTransport>         midi;
MidiHandler<MidiUartTransport>::Config midi_cfg;
float                                  semiMultiplier = 1;
float                                  osc1Freq[poly];
uint8_t                                finished;
int                                    navigation   = 0;
int                                    count        = 0;
bool                                   splashInit   = true;
int                                    polyIndexOn  = 0;
int                                    polyIndexOff = 0;
float                                  freq1;
float                                  freq2;

void HandleMidiMessage(MidiEvent m)
{
    switch(m.type)
    {
        case NoteOn:

        {
            if(polyIndexOn > poly - 1)
            {
                polyIndexOn = 0;
            }
            NoteOnEvent p = m.AsNoteOn();
            if(m.data[1] != 0)
            {
                line[polyIndexOn].Start(p.note + (synthmenu.glideInit * 0.25),
                                        p.note,
                                        synthmenu.glideTime / 100);
                gate[polyIndexOn] = true;

                freq1 = mtof(p.note + synthmenu.noteSemiAdd)
                        * (1 + synthmenu.freqFine);
                freq2 = mtof(p.note + synthmenu.noteSemiAdd2)
                        * (1 + synthmenu.freqFine2);
   osc[polyIndexOn].osc1.SetFreq(freq1);
        osc[polyIndexOn].osc2.SetFreq(freq2);
                polyIndexOn = polyIndexOn + 1;
            }
        }
        break;

        case NoteOff:
        {
            if(m.data[1] != 0)
            {
                if(polyIndexOff > poly - 1)
                {
                    polyIndexOff = 0;
                }
                gate[polyIndexOff] = false;
                polyIndexOff       = polyIndexOff + 1;
            }
        }
        break;
        default: break;
    }
}


void AudioCallback(AudioHandle::InterleavingInputBuffer  in,
                   AudioHandle::InterleavingOutputBuffer out,
                   size_t                                size)
{
    float osc_out;
    float env_out[32];
    for(size_t i = 0; i < size; i += 2)
    {
        for(size_t i = 0; i < poly; i++)
        {
            env_out[i] = env[i].Process(gate[i]);
        }

        for(size_t i = 0; i < poly; i++)
        {
            osc[i].osc1.SetAmp((env_out[i] * 0.5) * synthmenu.synthOn);
            osc[i].osc2.SetAmp((env_out[i] * 0.5) * synthmenu.synthOn2);
        }


        for(size_t i = 0; i < poly; i++)
        {
            if(i == 0)
            {
                osc_out = osc[i].osc1.Process() + osc[i].osc2.Process();
            }
            else
            {
                osc_out
                    = osc_out + osc[i].osc1.Process() + osc[i].osc2.Process();
            }
        }

        //osc_out    = osc[0].osc1.Process() + osc[0].osc2.Process();
        for(size_t i = 0; i < poly; i++)
        {
            osc1Freq[i] = line[i].Process(&finished);
        }


        out[i]     = osc_out * 0.25;
        out[i + 1] = osc_out * 0.25;
    }
}

int main(void)
{
    hw.Configure();
    hw.Init();
    sprintf(synthmenu.buff, "Semi_%dst", synthmenu.noteSemiAdd);
    sprintf(synthmenu.buff2, "Semi_%dst", synthmenu.noteSemiAdd2);
    sprintf(synthmenu.buffFine, "Fine_%d%%", (int)(synthmenu.freqFine * 100));
    sprintf(synthmenu.buffFine2, "Fine_%d%%", (int)(synthmenu.freqFine2 * 100));
    hw.usb_handle.Init(UsbHandle::FS_INTERNAL);
    System::Delay(250);
    //AdcChannelConfig adc_config[2];
    //adc_config[0].InitSingle(hw.GetPin(24));
    //adc_config[1].InitSingle(hw.GetPin(25));
    //hw.adc.Init(adc_config, 2);
    //hw.adc.Start();
    float                           samplerate = hw.AudioSampleRate();
    OledDisplayExtravaganza::Config disp_cfg;
    disp_cfg.driver_config.transport_config.pin_config.dc    = hw.GetPin(9);
    disp_cfg.driver_config.transport_config.pin_config.reset = hw.GetPin(30);
    screen.Init(disp_cfg);
    synthmenu.buttonLeft.Init(hw.GetPin(27), (samplerate));
    synthmenu.buttonRight.Init(hw.GetPin(26), (samplerate));
    synthmenu.encoderLeft.Init(
        hw.GetPin(16), hw.GetPin(17), hw.GetPin(15), samplerate);
    synthmenu.encoderRight.Init(
        hw.GetPin(19), hw.GetPin(20), hw.GetPin(18), samplerate);
    hw.StartAudio(AudioCallback);

    for(size_t i = 0; i < poly; i++)
    {
        osc[i].osc1.Init(samplerate);
        osc[i].osc1.SetWaveform(osc[i].osc1.WAVE_SIN);
        osc[i].osc1.SetAmp(0.5);
        osc[i].osc1.SetFreq(440);
        osc[i].osc2.Init(samplerate);
        osc[i].osc2.SetWaveform(osc[i].osc2.WAVE_SIN);
        osc[i].osc2.SetAmp(0.5);
        osc[i].osc2.SetFreq(440);
    }


    line[0].Init(samplerate);
    for(size_t i = 0; i < poly; i++)
    {
        env[i].Init(samplerate);
        env[i].SetTime(ADSR_SEG_ATTACK, .05);
        env[i].SetTime(ADSR_SEG_DECAY, .1);
        env[i].SetTime(ADSR_SEG_RELEASE, .25);
        env[i].SetSustainLevel(.5);
    }
    midi.Init(midi_cfg);
    midi.StartReceive();


    while(1)
    {
        if(synthmenu.analogRead > 1)
        {
            synthmenu.analogRead = 1;
        }
        if(synthmenu.analogRead < 0)
        {
            synthmenu.analogRead = 0;
        }

        midi.Listen();
        synthmenu.buttonLeft.Debounce();
        synthmenu.buttonRight.Debounce();
        synthmenu.encoderLeft.Debounce();
        synthmenu.encoderRight.Debounce();
        navigation += synthmenu.encoderLeft.Increment();
        if(splashInit == false)
        {
            if(navigation > 3)
            {
                navigation = 3;
            }
            if(navigation < 1)
            {
                navigation = 1;
            }
        }

        if(navigation == 0)
        {
            synthmenu.SplashScreen(screen);
            if(count > 1000)
            {
                navigation = 1;
                count      = 0;
                splashInit = false;
            }
            count++;
        }
        else if(navigation == 1)
        {
            synthmenu.Menu1(screen, osc);
        }
        else if(navigation == 2)
        {
            synthmenu.Menu2(screen, osc[0]);
        }
        else if(navigation == 3)
        {
            synthmenu.Menu3(screen, env);
        }


        if(midi.HasEvents())
        {
            HandleMidiMessage(midi.PopEvent());
        }
     
    }
}
