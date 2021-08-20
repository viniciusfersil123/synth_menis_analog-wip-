#ifndef Menus_H
#define Menus_H
#include "OledDisplayExtravaganza.h"
#include "daisy_seed.h"
#include "daisysp.h"

class Menus
{
  public:
    struct oscVoice
    {
        daisysp::Oscillator osc1;
         daisysp::Oscillator osc2;
    };

    Menus();
    void Menu1(OledDisplayExtravaganza screen, oscVoice& osc);
    void Menu2(OledDisplayExtravaganza screen, oscVoice osc);
    void Menu3(OledDisplayExtravaganza screen, oscVoice osc, daisysp::Adsr&);
    void
    Menu4(OledDisplayExtravaganza screen, oscVoice osc, daisysp::Adsr& env);
    bool OscSelect(float select);
    int  WaveSelect(float select);
    void SplashScreen(OledDisplayExtravaganza screen);

    float          analogRead;
    float          analogLastRead;
    bool           updateValue;
    daisy::Encoder encoderLeft;
    daisy::Encoder encoderRight;
    daisy::Switch  buttonLeft;
    daisy::Switch  buttonRight;
    int            menuState;
    int            menuStateGlide;
    bool           OscSelector;
    float          drawSliderSemi;
    float          drawSliderFine;
    float          drawSliderSemi2;
    float          drawSliderFine2;
    float          circleGlidePosition;
    float          circleGlideTimePosition;
    int            glideInit;
    float          glideTime;
    bool           toggleOsc;
    bool           toggleOsc2;
    int            selectedWave;
    int            selectedWave2;
    char           buff[24];
    char           buff2[24];
    char           buffFine[24];
    char           buffFine2[24];
    char           buffPitchGlide[24];
    char           buffPitchTime[24];
    char           buffAttackTime[24];
    char           buffDecayTime[24];
    int            noteSemiAdd;
    int            noteSemiAdd2;
    int            synthOn;
    int            synthOn2;
    float          freqFine;
    float          freqFine2;
    float          enconderScaleFactor;
    int            state;
    int            stateWave;
    int            toggleState;
    int            toggleState2;
    int            setWave;
    int            setWave2;
    float          attackTime;
    float          attackTimeFilter;
    float          decayTimeFilter;
    float          attackTimeScaleDraw;
    float          attackTimeFilterScaleDraw;
    int            menuStateEnv;
    int            menuStateEnvFilter;
    float          decayTime;
    float          decayTimeScaleDraw;
    float          decayTimeScaleFilterDraw;
    float          sustatinLevel;
    float          sustatinLevelFilter;
    float          sustatinLevelScaleDraw;
    float          sustatinLevelScaleFilterDraw;
    float          releaseTime;
    float          releaseTimeFilter;
    float          releaseTimeScaleDraw;
    float          releaseTimeScaleFilterDraw;
    float          displayAnimationMovY;
    bool           colorTemplate;


  private:
    bool on;
};


#endif