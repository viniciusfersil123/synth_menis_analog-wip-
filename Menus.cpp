#include "Menus.h"


Menus::Menus()
{
    this->on                      = true;
    this->analogRead              = 0;
    this->analogLastRead          = 0;
    this->updateValue             = false;
    this->menuState               = 0;
    this->menuStateGlide          = 0;
    this->OscSelector             = true;
    this->synthOn                 = 1;
    this->synthOn2                = 1;
    this->freqFine2               = 0;
    this->freqFine                = 0;
    this->analogRead              = 0;
    this->glideTime               = 1;
    this->circleGlideTimePosition = 64;
    this->state                   = 1;
    this->stateWave               = 0;
    this->toggleState             = 1;
    this->toggleState2            = 1;
    this->setWave                 = 0;
    this->setWave2                = 0;

    sprintf(this->buffPitchTime, "Time_50%%");
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

void Menus::Menu1(OledDisplayExtravaganza screen, daisysp::Oscillator osc[])

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
                    osc[0].SetWaveform(osc[0].WAVE_SIN);
                }
            }
            else if(setWave == 1)
            {
                for(int i = 0; i < 2; i++)
                {
                    selectedWave = setWave;
                    osc[0].SetWaveform(osc[0].WAVE_TRI);
                }
            }
            else if(setWave == 2)
            {
                for(int i = 0; i < 2; i++)
                {
                    selectedWave = setWave;
                    osc[0].SetWaveform(osc[0].WAVE_SQUARE);
                }
            }
            else if(setWave == 3)
            {
                for(int i = 0; i < 2; i++)
                {
                    selectedWave = setWave;
                    osc[0].SetWaveform(osc[0].WAVE_SAW);
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
                        osc[1].SetWaveform(osc[1].WAVE_SIN);
                    }
                }
                else if(setWave2 == 1)
                {
                    for(int i = 0; i < 2; i++)
                    {
                        selectedWave2 = setWave2;
                        osc[1].SetWaveform(osc[1].WAVE_TRI);
                    }
                }
                else if(setWave2 == 2)
                {
                    for(int i = 0; i < 2; i++)
                    {
                        selectedWave2 = setWave2;
                        osc[1].SetWaveform(osc[1].WAVE_SQUARE);
                    }
                }
                else if(setWave2 == 3)
                {
                    for(int i = 0; i < 2; i++)
                    {
                        selectedWave2 = setWave2;
                        osc[1].SetWaveform(osc[1].WAVE_SAW);
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
            this->drawSliderFine += (((float)this->encoderRight.Increment()) / 32);
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
            this->drawSliderFine2 += (((float)this->encoderRight.Increment()) / 32);
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

void Menus::Menu2(OledDisplayExtravaganza screen, daisysp::Oscillator osc[])
{
    screen.Fill(false);

    if(abs(this->analogRead - this->analogLastRead) > 0.001)
    {
        this->updateValue = true;
    }
    else
    {
        this->updateValue = false;
    }
    float glideInit;
    float margin = 10;
    float offset = (screen.Height() / 4);
    glideInit    = (offset + (this->analogRead * screen.Height() * 0.625));
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
        if(this->updateValue)
        {
            circleGlidePosition = ((screen.Height()) + margin) - glideInit;
            sprintf(this->buffPitchGlide,
                    "Init_%d%%",
                    (int)(((glideInit - offset) / 40) * 200) - 100);
            this->glideInit = (this->analogRead * 24) - 12;
        }
        screen.DrawRect(0, 0, 66, 13, true, false);
    }
    else if(this->menuStateGlide == 1)
    {
        if(this->updateValue)
        {
            circleGlideTimePosition
                = ((this->analogRead * screen.Width() * 0.8) + margin);
            this->glideTime = this->analogRead * 2;
            sprintf(this->buffPitchTime,
                    "Time_%d%%",
                    (int)(((glideInit - offset) / 40) * 100) - 0);
        }
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
    for(int i = 0; i < screen.Width(); i++)
    {
        screen.DrawPixel(i * 3, (screen.Height() / 2), on);
    }
    this->analogLastRead = this->analogRead;

    screen.Update();
}