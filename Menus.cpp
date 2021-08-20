#include "Menus.h"


Menus::Menus()
{
    this->on                      = true;
    this->analogRead              = 0;
    this->analogLastRead          = 0;
    this->updateValue             = false;
    this->menuState               = 0;
    this->menuStateGlide          = 0;
    this->menuStateEnv            = 0;
    this->menuStateEnvFilter      = 0;
    this->OscSelector             = true;
    this->synthOn                 = 1;
    this->synthOn2                = 1;
    this->freqFine2               = 0;
    this->freqFine                = 0;
    this->analogRead              = 0;
    this->glideTime               = 1;
    this->circleGlideTimePosition = 10;
    this->state                   = 1;
    this->stateWave               = 0;
    this->toggleState             = 1;
    this->toggleState2            = 1;
    this->setWave                 = 0;
    this->setWave2                = 0;
    this->attackTime              = 0.1f;
    this->attackTime              = 0.5f;
    this->attackTimeScaleDraw     = 0.5f;
    this-> colorTemplate = false;

    sprintf(this->buffPitchTime, "Time_0%%");
}

void Menus::SplashScreen(OledDisplayExtravaganza screen)
{
    
   
    screen.Fill(colorTemplate);

    /**
 * Made with Marlin Bitmap Converter
 * https://marlinfw.org/tools/u8glib/converter.html
 *
 * This bitmap from the file 'pt.png'
 */
    
   /*  const unsigned char pt[] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xca, 0x96, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xca, 0x96, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x8a, 0x96, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x8a, 0x96, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x8a, 0x96, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x8a, 0x96, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x8a, 0x86, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0a, 0x86, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x28, 0x86, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x2a, 0xa6, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x2a, 0x86, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x2a, 0x86, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x2a, 0x86, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x2a, 0x96, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x2a, 0x96, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x2a, 0x96, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x2a, 0x96, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x2a, 0x96, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

        unsigned char bits[sizeof(pt)*8]={};

    for(int i = 0; i < (sizeof(pt) * 8)-1; i++)
    {
        bits[i] = ((128>> (i % 8)) & (pt[i/8])) ;
    }

    for(int x = 0; x < screen.Width(); x++)
    {
        for(int y = 0; y < screen.Height(); y++)
        {
            screen.DrawPixel(x,y,bits[x+y*screen.Width()]);
        }
    } */

    
    screen.DrawRect(screen.Width()/2-10,6,screen.Width()/2+12,33,!colorTemplate,true);
    //M
    screen.DrawLine(screen.Width()/2-10,37,screen.Width()/2-10,52,!colorTemplate);
    screen.DrawLine(screen.Width()/2-10,37,screen.Width()/2-10+3,52,!colorTemplate);
    screen.DrawLine(screen.Width()/2-10+3,52,screen.Width()/2-10+6,37,!colorTemplate);
    screen.DrawLine(screen.Width()/2-10+6,37,screen.Width()/2-10+6,52,!colorTemplate);
    //H
    screen.DrawLine(screen.Width()/2-10+8,52,screen.Width()/2-10+8,37,!colorTemplate);
     screen.DrawLine(screen.Width()/2-10+8,45,screen.Width()/2-10+11,45,!colorTemplate);
     screen.DrawLine(screen.Width()/2-10+11,52,screen.Width()/2-10+11,37,!colorTemplate);
     //N
    screen.DrawLine(screen.Width()/2-10+13,37,screen.Width()/2-10+13,52,!colorTemplate);
    screen.DrawLine(screen.Width()/2-10+13,37,screen.Width()/2-10+16,52,!colorTemplate);
    screen.DrawLine(screen.Width()/2-10+16,52,screen.Width()/2-10+16,37,!colorTemplate);
    //I
    screen.DrawLine(screen.Width()/2-10+18,52,screen.Width()/2-10+18,37,!colorTemplate);
    
    //S
    screen.DrawLine(screen.Width()/2-10+20,37,screen.Width()/2-10+22,37,!colorTemplate);
    screen.DrawLine(screen.Width()/2-10+20,37,screen.Width()/2-10+22,44,!colorTemplate);
    screen.DrawLine(screen.Width()/2-10+22,44,screen.Width()/2-10+20,52,!colorTemplate);
    screen.DrawLine(screen.Width()/2-10+20,52,screen.Width()/2-10+22,52,!colorTemplate);
    //Animation Overlay
    screen.DrawRect(0,displayAnimationMovY+2,screen.Width(),(screen.Height()/2+displayAnimationMovY)+2,colorTemplate,true);
    displayAnimationMovY = displayAnimationMovY - 0.1;
    screen.DrawRect(0,screen.Height()/2-(displayAnimationMovY+2),screen.Width(),(screen.Height()-displayAnimationMovY)+2,colorTemplate,true);

 
 
    
    screen.Update();
}


int Menus::WaveSelect(float select)
{
    this->stateWave += this->encoderRight.Increment();
    int state;
    if(this->stateWave > 3)
    {
        this->stateWave = 3;
    }
    if(this->stateWave < 0)
    {
        this->stateWave = 0;
    }

    if(this->stateWave == 0)
    {
        state = 0;
        return state;
    }
    else if(this->stateWave == 1)
    {
        state = 1;
        return state;
    }
    else if(this->stateWave == 2)
    {
        state = 2;
        return state;
    }
    else if(this->stateWave == 3)
    {
        state = 3;
        return state;
    }
}

bool Menus::OscSelect(float select)
{
    this->state += this->encoderRight.Increment();
    if(this->state > 1)
    {
        this->state = 1;
    }
    if(this->state < 0)
    {
        this->state = 0;
    }


    if(this->state == 1)
    {
        state = true;
        return state;
    }
    else
    {
        state = false;
        return state;
    }
}

void Menus::Menu1(OledDisplayExtravaganza screen, oscVoice& osc)

{
    screen.Fill(!on);
    if(this->buttonLeft.RisingEdge())

    {
        menuState = menuState - 1;
        if(menuState < 0)
        {
            menuState = 3;
        }
    }
    if(this->buttonRight.RisingEdge())

    {
        menuState = menuState + 1;
        if(menuState > 3)
        {
            menuState = 0;
        }
    }

    screen.drawHorizontalToggle(46, 13, 8, on, this->OscSelector, "");

    if(this->OscSelector == true)
    {
        screen.drawSlider(70, 7, 50, 3, on, ((this->drawSliderSemi)) / 40);
        screen.drawSlider(70, 40, 50, 3, on, drawSliderFine);
        screen.drawVerticalToggle(13, 51, 8, on, this->toggleOsc, "");
        screen.WaveIcons(35, 42, 55, this->selectedWave, on);
        screen.SetCursor(70, 17);
        screen.WriteString(this->buff, Font_6x8, true);
        screen.SetCursor(70, 50);
        screen.WriteString(this->buffFine, Font_6x8, true);
    }
    else
    {
        screen.drawSlider(70, 7, 50, 3, false, (this->drawSliderSemi2) / 40);
        screen.drawSlider(70, 40, 50, 3, false, drawSliderFine2);
        screen.drawVerticalToggle(13, 51, 8, false, this->toggleOsc2, "");
        screen.WaveIcons(35, 42, 55, this->selectedWave2, false);
        screen.SetCursor(70, 17);
        screen.WriteString(this->buff2, Font_6x8, false);
        screen.SetCursor(70, 50);
        screen.WriteString(this->buffFine2, Font_6x8, false);
    }


    screen.SetCursor(4, 8);
    screen.WriteString("Osc", Font_7x10, on);


    for(int i = 0; i < screen.Width(); i++)
    {
        screen.DrawPixel(i * 3, (screen.Height() / 2) - 3, on);
    }
    for(int i = 0; i < screen.Height(); i++)
    {
        screen.DrawPixel(60, i * 2, on);
    }
    for(int i = screen.Height() / 4 - 1; i < screen.Height(); i++)
    {
        screen.DrawPixel(29, i * 2, on);
    }

    if(encoderLeft.RisingEdge())
    {
        this->OscSelector = !this->OscSelector;
        on                = this->OscSelector;
    }
    else if(menuState == 0)
    {
        if(this->OscSelector == true)
        {
            if(this->noteSemiAdd > 32)
            {
                this->noteSemiAdd = 32;
            }
            if(this->noteSemiAdd < 0)
            {
                this->noteSemiAdd = 0;
            }
            if(this->drawSliderSemi >= 40)
            {
                this->drawSliderSemi = 40;
            }
            if(this->drawSliderSemi < 0)
            {
                this->drawSliderSemi = 0;
            }
            this->noteSemiAdd += this->encoderRight.Increment();
            this->drawSliderSemi
                += (((float)this->encoderRight.Increment()) / 32) * 40;
            sprintf(this->buff, "Semi_%dst", this->noteSemiAdd);
        }
        else
        {
            if(this->noteSemiAdd2 > 32)
            {
                this->noteSemiAdd2 = 32;
            }
            if(this->noteSemiAdd2 < 0)
            {
                this->noteSemiAdd2 = 0;
            }
            if(this->drawSliderSemi2 >= 40)
            {
                this->drawSliderSemi2 = 40;
            }
            if(this->drawSliderSemi2 < 0)
            {
                this->drawSliderSemi2 = 0;
            }
            this->noteSemiAdd2 += (float)this->encoderRight.Increment();
            this->drawSliderSemi2
                += (((float)this->encoderRight.Increment()) / 32) * 40;
            sprintf(this->buff2, "Semi_%dst", this->noteSemiAdd2);
        }


        screen.DrawRect(
            60, 0, screen.Width() - 1, screen.Height() / 2 - 3, on, false);
    }
    else if(menuState == 1)
    {
        if(this->OscSelector == true)

        {
            if(this->encoderRight.Increment() == 1)
            {
                synthOn         = 1;
                this->toggleOsc = false;
            }
            if(this->encoderRight.Increment() == -1)
            {
                synthOn         = 0;
                this->toggleOsc = true;
            }
        }
        else
        {
            if(this->encoderRight.Increment() == 1)
            {
                synthOn2         = 1;
                this->toggleOsc2 = false;
            }
            if(this->encoderRight.Increment() == -1)
            {
                synthOn2         = 0;
                this->toggleOsc2 = true;
            }
        }

        screen.DrawRect(
            0, screen.Height() / 2 - 3, 29, screen.Height() - 1, on, false);
    }
    else if(menuState == 2)
    {
        if(this->OscSelector == true)
        {
            this->setWave += this->encoderRight.Increment();
            if(setWave > 3)
            {
                this->setWave = 3;
            }
            if(this->setWave < 0)
            {
                this->setWave = 0;
            }
            if(this->setWave == 0)
            {
                for(int i = 0; i < 2; i++)
                {
                    selectedWave = setWave;
                    osc.osc1.SetWaveform(osc.osc1.WAVE_SIN);
                }
            }
            else if(setWave == 1)
            {
                for(int i = 0; i < 2; i++)
                {
                    selectedWave = setWave;
                    osc.osc1.SetWaveform(osc.osc1.WAVE_TRI);
                }
            }
            else if(setWave == 2)
            {
                for(int i = 0; i < 2; i++)
                {
                    selectedWave = setWave;
                    osc.osc1.SetWaveform(osc.osc1.WAVE_SQUARE);
                }
            }
            else if(setWave == 3)
            {
                for(int i = 0; i < 2; i++)
                {
                    selectedWave = setWave;
                    osc.osc1.SetWaveform(osc.osc1.WAVE_SAW);
                }
            }
        }
        {
            if(this->OscSelector == false)
            {
                if(setWave2 > 3)
                {
                    this->setWave2 = 3;
                }
                if(this->setWave2 < 0)
                {
                    this->setWave2 = 0;
                }
                this->setWave2 += this->encoderRight.Increment();
                if(setWave2 > 3)
                {
                    this->setWave2 = 3;
                }
                if(this->setWave2 < 0)
                {
                    this->setWave2 = 0;
                }
                if(this->setWave2 == 0)
                {
                    for(int i = 0; i < 2; i++)
                    {
                        selectedWave2 = setWave2;
                        osc.osc2.SetWaveform(osc.osc2.WAVE_SIN);
                    }
                }
                else if(setWave2 == 1)
                {
                    for(int i = 0; i < 2; i++)
                    {
                        selectedWave2 = setWave2;
                        osc.osc2.SetWaveform(osc.osc2.WAVE_TRI);
                    }
                }
                else if(setWave2 == 2)
                {
                    for(int i = 0; i < 2; i++)
                    {
                        selectedWave2 = setWave2;
                        osc.osc2.SetWaveform(osc.osc2.WAVE_SQUARE);
                    }
                }
                else if(setWave2 == 3)
                {
                    for(int i = 0; i < 2; i++)
                    {
                        selectedWave2 = setWave2;
                        osc.osc2.SetWaveform(osc.osc2.WAVE_SAW);
                    }
                }
            }


            screen.DrawRect(29,
                            screen.Height() / 2 - 3,
                            60,
                            screen.Height() - 1,
                            on,
                            false);
        }
    }
    else if(menuState == 3)
    {
        /*  this->noteSemiAdd
                += (((float)this->encoderRight.Increment()) / 32) * 40;
            this->drawSliderSemi
                += ((float)this->encoderRight.Increment()) / 32; */


        if(this->OscSelector == true)
        {
            if(this->freqFine >= 1)
            {
                this->freqFine = 1;
            }
            if(this->freqFine < 0)
            {
                this->freqFine = 0;
            }
            if(this->drawSliderFine >= 1)
            {
                this->drawSliderFine = 1;
            }
            if(this->drawSliderFine < 0)
            {
                this->drawSliderFine = 0;
            }

            this->freqFine += (((float)this->encoderRight.Increment()) / 32);
            this->drawSliderFine
                += (((float)this->encoderRight.Increment()) / 32);
            sprintf(this->buffFine, "Fine_%d%%", (int)(freqFine * 100));
        }
        else
        {
            if(this->freqFine2 > 1)
            {
                this->freqFine2 = 1;
            }
            if(this->freqFine2 < 0)
            {
                this->freqFine2 = 0;
            }
            if(this->drawSliderFine2 >= 1)
            {
                this->drawSliderFine2 = 1;
            }
            if(this->drawSliderFine2 < 0)
            {
                this->drawSliderFine2 = 0;
            }

            this->freqFine2 += (((float)this->encoderRight.Increment()) / 32);
            this->drawSliderFine2
                += (((float)this->encoderRight.Increment()) / 32);
            sprintf(this->buffFine2, "Fine_%d%%", (int)(freqFine2 * 100));
        }

        screen.DrawRect(60,
                        screen.Height() / 2 - 3,
                        screen.Width() - 1,
                        screen.Height() - 1,
                        on,
                        false);
    }
    //noteCross            = noteCross + (this->drawSliderSemi * 100);
    screen.Update();
}

void Menus::Menu2(OledDisplayExtravaganza screen, oscVoice osc)
{
    screen.Fill(false);
    float margin = 10;
    float glideInit;
    float offset = (screen.Height() / 4);
    glideInit    = (offset + (this->analogRead * screen.Height() * 0.625));
    for(int i = 0; i < screen.Width(); i++)
    {
        screen.DrawPixel(i * 3, (screen.Height() / 2), true);
    }
    if(this->buttonLeft.RisingEdge())

    {
        this->menuStateGlide = this->menuStateGlide - 1;
        if(this->menuStateGlide < 0)
        {
            this->menuStateGlide = 1;
        }
    }
    if(this->buttonRight.RisingEdge())

    {
        this->menuStateGlide = this->menuStateGlide + 1;
        if(this->menuStateGlide > 1)
        {
            this->menuStateGlide = 0;
        }
    }
    if(this->menuStateGlide == 0)
    {
        if(this->glideInit > 100)
        {
            this->glideInit = 100;
        }
        if(this->glideInit < -100)
        {
            this->glideInit = -100;
        }

        int glideScale;
        glideScale = screen.Height() - ((this->glideInit + 212) * 0.15);
        this->glideInit += this->encoderRight.Increment();
        circleGlidePosition = glideScale;

        sprintf(this->buffPitchGlide, "Init_%d%%", this->glideInit);


        //(this->analogRead * 24) - 12;

        screen.DrawRect(0, 0, 66, 13, true, false);
    }
    else if(this->menuStateGlide == 1)
    {
        if(this->glideTime >= 100)
        {
            this->glideTime = 100;
        }
        if(this->glideTime <= 0)
        {
            this->glideTime = 0;
        }
        if(circleGlidePosition >= 100)
        {
            circleGlidePosition = 100;
        }
        if(circleGlidePosition <= 0)
        {
            circleGlidePosition = 0;
        }
        if(circleGlideTimePosition >= 100)
        {
            circleGlideTimePosition = 100;
        }
        if(circleGlideTimePosition <= 10)
        {
            circleGlideTimePosition = 10;
        }
        circleGlideTimePosition += this->encoderRight.Increment();
        ;
        this->glideTime += this->encoderRight.Increment();
        sprintf(this->buffPitchTime, "Time_%d%%", (int)this->glideTime);
        screen.DrawRect(67, 0, screen.Width() - 2, 13, true, false);
    }

    screen.SetCursor(6, 4);
    screen.WriteString(buffPitchGlide, Font_6x8, true);
    screen.SetCursor(73, 4);
    screen.WriteString(buffPitchTime, Font_6x8, true);
    screen.DrawLine(margin,
                    circleGlidePosition,
                    circleGlideTimePosition,
                    screen.Height() / 2,
                    true);
    screen.DrawCircle(margin, circleGlidePosition, 3, true);
    screen.DrawCircle(circleGlideTimePosition, screen.Height() / 2, 3, true);


    screen.Update();
}


void Menus::Menu3(OledDisplayExtravaganza screen,
                  oscVoice osc,
                  daisysp::Adsr&          env)
{
    screen.Fill(false);
    if(this->buttonLeft.RisingEdge())

    {
        this->menuStateEnv = this->menuStateEnv - 1;
        if(this->menuStateEnv < 0)
        {
            this->menuStateEnv = 3;
        }
    }
    if(this->buttonRight.RisingEdge())

    {
        this->menuStateEnv = this->menuStateEnv + 1;
        if(this->menuStateEnv > 3)
        {
            this->menuStateEnv = 0;
        }
    }
    if(menuStateEnv == 0)
    {
        this->attackTime += this->encoderRight.Increment() * 3.3;
        env.SetTime(daisysp::ADSR_SEG_ATTACK, this->attackTime / 100);
        this->attackTimeScaleDraw += this->encoderRight.Increment();
        if(attackTimeScaleDraw >= screen.Width() / 4)
        {
            attackTimeScaleDraw = screen.Width() / 4;
        }
        if(attackTimeScaleDraw <= 0)
        {
            attackTimeScaleDraw = 0;
        }
        if(attackTime >= 100)
        {
            attackTime = 100;
        }
        if(attackTime <= 0)
        {
            attackTime = 0;
        }
        screen.DrawRect(28, 0, 40, 13, true, false);
    }
    if(menuStateEnv == 1)
    {
        this->decayTime += this->encoderRight.Increment() * 3.3;
        env.SetTime(daisysp::ADSR_SEG_DECAY, this->decayTime / 100);
        this->decayTimeScaleDraw += this->encoderRight.Increment();
        if(decayTimeScaleDraw >= screen.Width() / 4)
        {
            decayTimeScaleDraw = screen.Width() / 4;
        }
        if(decayTimeScaleDraw <= 0)
        {
            decayTimeScaleDraw = 0;
        }
        if(decayTime >= 100)
        {
            decayTime = 100;
        }
        if(decayTime <= 0)
        {
            decayTime = 0;
        }
        screen.DrawRect(44, 0, 56, 13, true, false);
    }
    if(menuStateEnv == 2)
    {
        this->sustatinLevel += this->encoderRight.Increment() * 3.3;
        env.SetSustainLevel(this->sustatinLevel / 100);
        this->sustatinLevelScaleDraw += this->encoderRight.Increment();
        if(this->sustatinLevelScaleDraw >= screen.Width() / 4)
        {
            this->sustatinLevelScaleDraw = screen.Width() / 4;
        }
        if(this->sustatinLevelScaleDraw <= 0)
        {
            this->sustatinLevelScaleDraw = 0;
        }
        if(this->sustatinLevel >= 100)
        {
            this->sustatinLevel = 100;
        }
        if(this->sustatinLevel <= 0)
        {
            this->sustatinLevel = 0;
        }
        screen.DrawRect(60, 0, 72, 13, true, false);
    }
    if(menuStateEnv == 3)
    {
        this->releaseTime += this->encoderRight.Increment() * 3.3;
        env.SetTime(daisysp::ADSR_SEG_RELEASE, this->releaseTime / 100);
        this->releaseTimeScaleDraw += this->encoderRight.Increment();
        if(this->releaseTimeScaleDraw >= screen.Width() / 4)
        {
            this->releaseTimeScaleDraw = screen.Width() / 4;
        }
        if(this->releaseTimeScaleDraw <= 0)
        {
            this->releaseTimeScaleDraw = 0;
        }
        if(this->releaseTime >= 100)
        {
            this->releaseTime = 100;
        }
        if(this->releaseTime <= 0)
        {
            this->releaseTime = 0;
        }
        screen.DrawRect(76, 0, 88, 13, true, false);
    }

    screen.SetCursor(32, 4);
    screen.WriteString("A", Font_6x8, true);
    screen.SetCursor(48, 4);
    screen.WriteString("D", Font_6x8, true);
    screen.SetCursor(64, 4);
    screen.WriteString("S", Font_6x8, true);
    screen.SetCursor(80, 4);
    screen.WriteString("R", Font_6x8, true);
    screen.DrawLine(0, screen.Height() - 5, attackTimeScaleDraw, 25, true);
    screen.DrawLine(attackTimeScaleDraw,
                    25,
                    attackTimeScaleDraw + decayTimeScaleDraw,
                    (screen.Height() - 5) - sustatinLevelScaleDraw,
                    true);

    screen.DrawLine(attackTimeScaleDraw + decayTimeScaleDraw,
                    (screen.Height() - 5) - sustatinLevelScaleDraw,
                    attackTimeScaleDraw + decayTimeScaleDraw
                        + screen.Width() / 4,
                    (screen.Height() - 5) - sustatinLevelScaleDraw,
                    true);
    screen.DrawLine(attackTimeScaleDraw + decayTimeScaleDraw
                        + screen.Width() / 4,
                    (screen.Height() - 5) - sustatinLevelScaleDraw,
                    attackTimeScaleDraw + decayTimeScaleDraw
                        + screen.Width() / 4 + releaseTimeScaleDraw,
                    screen.Height() - 5,
                    true);


    screen.Update();
}

void Menus::Menu4(OledDisplayExtravaganza screen,
                  oscVoice osc,
                  daisysp::Adsr&          env)
{
    screen.Fill(true);
    // MENIS & CREDITS & MAP CV PORT
    screen.Update();
}