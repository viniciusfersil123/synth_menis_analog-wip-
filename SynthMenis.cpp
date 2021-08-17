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
Oscillator                             osc[2];
Line                                   line;
Adsr                                   env;
bool                                   gate;
MidiHandler<MidiUartTransport>         midi;
MidiHandler<MidiUartTransport>::Config midi_cfg;
float                                  semiMultiplier = 1;
float                                  osc1Freq       = 0;
uint8_t                                finished;
int                                    navigation = 0;

void HandleMidiMessage(MidiEvent m)
{
    switch(m.type)
    {
        case NoteOn:
        {
            NoteOnEvent p = m.AsNoteOn();
            char        buff[512];
            sprintf(buff,
                    "Note Received:\t%d\t%d\t%d\r\n",
                    m.channel,
                    m.data[0],
                    m.data[1]);
            hw.usb_handle.TransmitInternal((uint8_t *)buff, strlen(buff));
            // This is to avoid Max/MSP Note outs for now..
            if(m.data[1] != 0)
            {
                //osc1Freq = p.note;
                line.Start(p.note + (synthmenu.glideInit * 0.25),
                           p.note,
                           synthmenu.glideTime / 100);
                gate = true;
                //env.Retrigger(true);
            }
        }
        break;

        case NoteOff:
        {
            char buff[512];
            sprintf(buff,
                    "NoteOff Received:\t%d\t%d\t%d\r\n",
                    m.channel,
                    m.data[0],
                    m.data[1]);
            hw.usb_handle.TransmitInternal((uint8_t *)buff, strlen(buff));
            // This is to avoid Max/MSP Note outs for now..
            if(m.data[1] != 0)
            {
                gate = false;
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
    float env_out;
    for(size_t i = 0; i < size; i += 2)
    {
        env_out = env.Process(gate);

        osc[0].SetAmp((env_out * 0.5) * synthmenu.synthOn);
        osc[1].SetAmp((env_out * 0.5) * synthmenu.synthOn2);
        osc_out    = osc[0].Process() + osc[1].Process();
        osc1Freq   = line.Process(&finished);
        out[i]     = osc_out;
        out[i + 1] = osc_out;
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

    for(int i = 0; i < 2; i++)
    {
        osc[i].Init(samplerate);
        osc[i].SetWaveform(osc[i].WAVE_SIN);
        osc[i].SetAmp(0.5);
        osc[i].SetFreq(440);
    }
    line.Init(samplerate);
    env.Init(samplerate);
    env.SetTime(ADSR_SEG_ATTACK, .05);
    env.SetTime(ADSR_SEG_DECAY, .1);
    env.SetTime(ADSR_SEG_RELEASE, .25);
    env.SetSustainLevel(.5);
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
        if(navigation > 2)
        {
            navigation = 2;
        }
        if(navigation < 0)
        {
            navigation = 0;
        }

        if(navigation == 0)
        {
            synthmenu.Menu1(screen, osc);
        }
        else if(navigation == 1)
        {
            synthmenu.Menu2(screen, osc);
        }
        else if(navigation == 2)
        {
            synthmenu.Menu3(screen, osc,env);
        }


        if(midi.HasEvents())
        {
            HandleMidiMessage(midi.PopEvent());
        }
        osc[0].SetFreq(mtof(osc1Freq + synthmenu.noteSemiAdd)
                       * (1 + synthmenu.freqFine));
        osc[1].SetFreq(mtof(osc1Freq + synthmenu.noteSemiAdd2)
                       * (1 + synthmenu.freqFine2));
    }
}
