#ifndef Menus_H
#define Menus_H
#include "OledDisplayExtravaganza.h"
#include "daisy_seed.h"
#include "daisysp.h"

class Menus
{
  public:
    Menus();
    void Menu1(OledDisplayExtravaganza screen, daisysp::Oscillator osc[]);
    void Menu2(OledDisplayExtravaganza screen, daisysp::Oscillator osc[]);
    bool OscSelect(float select);
    int  WaveSelect(float select);

    float         analogRead;
    float         analogReadNav;
    float         analogLastRead;
    bool          updateValue;
    daisy::Switch buttonLeft;
    daisy::Switch buttonRight;
    int           menuState;
    int           menuStateGlide;
    bool          OscSelector;
    float         drawSliderSemi;
    float         drawSliderFine;
    float         drawSliderSemi2;
    float         drawSliderFine2;
    float         circleGlidePosition;
    float         circleGlideTimePosition;
    float         glideInit;
    float         glideTime;
    bool          toggleOsc;
    bool          toggleOsc2;
    int           selectedWave;
    int           selectedWave2;
    char          buff[24];
    char          buff2[24];
    char          buffFine[24];
    char          buffFine2[24];
    char          buffPitchGlide[24];
    char          buffPitchTime[24];
    int           noteSemiAdd;
    int           noteSemiAdd2;
    int           synthOn;
    int           synthOn2;
    float         freqFine;
    float         freqFine2;

  private:
    bool on;
};


#endif