#ifndef OledDisplayExtravaganza_H
#define OledDisplayExtravaganza_H
#include "daisy_seed.h"
#include "dev/oled_ssd130x.h"
#include <stdio.h>
#include <math.h>


class OledDisplayExtravaganza
: public daisy::OledDisplay<daisy::SSD130x4WireSpi128x64Driver>
{
  private:
    void drawSine(float x, float y, float points, bool on);
    void drawTri(float x, float y, float points, bool on);
    void drawSqr(float xinit, float yinit, float points, bool on);
    void drawSaw(float xinit, float yinit, float points, bool on);
        /* data */
        public : OledDisplayExtravaganza(/* args */);
    void drawDial(float       x,
                  float       y,
                  float       radius,
                  float       sweep,
                  bool        on,
                  const char* label);
    void Selector(float x, float y, float width, float height, bool on);
    void WaveIcons(int xinit, int yinit, int points, int selector, bool on);
    void drawSlider(float x,
                    float y,
                    float width,
                    float height,
                    float on,
                    float amount);
    void drawHorizontalToggle(float       x,
                              float       y,
                              float       radius,
                              bool        on,
                              bool        state,
                              const char* label);
    void drawVerticalToggle(float       x,
                            float       y,
                            float       radius,
                            bool        on,
                            bool        state,
                            const char* label);
};


#endif