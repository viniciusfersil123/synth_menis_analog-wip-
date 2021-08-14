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
    this->freqFine2               = 1;
    this->freqFine                = 1;
    this->analogRead              = 0;
    this->glideTime               = 1;
    this->circleGlideTimePosition = 64;
    sprintf(this->buffPitchTime,"Time_50%%");
    
}

int Menus::WaveSelect(float select)
{
    int state;
    if(select >= 0 && select < 0.25)
    {
        state = 0;
        return state;
    }
    else if(select >= 0 && select < 0.5)
    {
        state = 1;
        return state;
    }
    else if(select >= 0.5 && select < 0.75)
    {
        state = 2;
        return state;
    }
    else if(select >= 0.75 && select < 1)
    {
        state = 3;
        return state;
    }
}

bool Menus::OscSelect(float select)
{
    bool state;
    if(select >= 0.5)
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
            menuState = 4;
        }
    }
    if(this->buttonRight.RisingEdge())

    {
        menuState = menuState + 1;
        if(menuState > 4)
        {
            menuState = 0;
        }
    }

    screen.drawHorizontalToggle(46, 13, 8, on, this->OscSelector, "");

    if(this->OscSelector == true)
    {
        screen.drawSlider(70, 7, 50, 3, on, this->drawSliderSemi);
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
        screen.drawSlider(70, 7, 50, 3, false, this->drawSliderSemi2);
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

    if(menuState == 0)
    {
        
            this->OscSelector = OscSelect(this->analogRead);
            on                = this->OscSelector;
        
        screen.DrawRect(0, 0, 60, screen.Height() / 2 - 3, on, false);
    }
    else if(menuState == 1)
    {
       
            if(this->OscSelector == true)
            {
                this->noteSemiAdd    = this->analogRead * 40;
                this->drawSliderSemi = this->analogRead;
                sprintf(this->buff, "Semi_%dst", this->noteSemiAdd);
            }
            else
            {
                this->noteSemiAdd2    = this->analogRead * 40;
                this->drawSliderSemi2 = this->analogRead;
                sprintf(this->buff2, "Semi_%dst", this->noteSemiAdd2);
            }
        

        screen.DrawRect(
            60, 0, screen.Width() - 1, screen.Height() / 2 - 3, on, false);
    }
    else if(menuState == 2)
    {
        
            if(this->OscSelector == true)
            {
                this->toggleOsc = !OscSelect(this->analogRead);
                if(OscSelect(this->analogRead))
                {
                    synthOn = 1;
                }
                else
                {
                    synthOn = 0;
                }
            }
            else
            {
                this->toggleOsc2 = !OscSelect(this->analogRead);
                if(OscSelect(this->analogRead))
                {
                    synthOn2 = 1;
                }
                else
                {
                    synthOn2 = 0;
                }
            }
        
        screen.DrawRect(
            0, screen.Height() / 2 - 3, 29, screen.Height() - 1, on, false);
    }
    else if(menuState == 3)
    {
        
            int setWave;
            selectedWave = WaveSelect(this->analogRead);
            setWave      = selectedWave;
            if(setWave == 0)
            {
                for(int i = 0; i < 2; i++)
                {
                    if(this->OscSelector == true)
                    {
                        selectedWave = setWave;
                        osc[0].SetWaveform(osc[0].WAVE_SIN);
                    }
                    else
                    {
                        selectedWave2 = setWave;
                        osc[1].SetWaveform(osc[1].WAVE_SIN);
                    }
                }
            }
            else if(setWave == 1)
            {
                if(OscSelector == true)
                {
                    selectedWave = setWave;
                    osc[0].SetWaveform(osc[0].WAVE_TRI);
                }
                else
                {
                    selectedWave2 = setWave;
                    osc[1].SetWaveform(osc[1].WAVE_TRI);
                }
            }
            else if(setWave == 2)
            {
                if(this->OscSelector == true)
                {
                    selectedWave = setWave;
                    osc[0].SetWaveform(osc[0].WAVE_SQUARE);
                }
                else
                {
                    selectedWave2 = setWave;
                    osc[1].SetWaveform(osc[1].WAVE_SQUARE);
                }
            }
            else if(setWave == 3)
            {
                if(OscSelector == true)
                {
                    selectedWave = setWave;
                    osc[0].SetWaveform(osc[0].WAVE_SAW);
                }
                else
                {
                    selectedWave2 = setWave;
                    osc[1].SetWaveform(osc[1].WAVE_SAW);
                }
            }
        
        screen.DrawRect(
            29, screen.Height() / 2 - 3, 60, screen.Height() - 1, on, false);
    }
    else if(menuState == 4)
    {
        
            if(this->OscSelector == true)
            {
                drawSliderFine = this->analogRead;
                freqFine       = this->analogRead;
                sprintf(this->buffFine, "Fine_%d%%", (int)(freqFine * 100));
            }
            else
            {
                drawSliderFine2 = this->analogRead;
                freqFine2       = this->analogRead;
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