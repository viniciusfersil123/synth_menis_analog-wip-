#include "OledDisplayExtravaganza.h"

OledDisplayExtravaganza::OledDisplayExtravaganza() {}

void OledDisplayExtravaganza::drawSlider(float x,
                                         float y,
                                         float width,
                                         float height,
                                         float on,
                                         float amount)
{
    OledDisplay::DrawRect(x, y, x + width * amount, y + height, on, true);
}


void OledDisplayExtravaganza::drawSine(float x, float y, float points, bool on)
{
    float ang = 0;
    for(int i = x; i < points; i++)
    {
        DrawLine(
            i, y + sin(ang * 3.3) * 8, i - 1, y + sin((ang - 0.1) * 3) * 8, on);

        ang = ang + 0.1;
    }
}

void OledDisplayExtravaganza::drawTri(float xinit,
                                      float yinit,
                                      float points,
                                      bool  on)
{
    DrawLine(xinit, yinit + 6, xinit + 9, yinit - 8, on);
    DrawLine(xinit + 18, yinit + 6, xinit + 9, yinit - 8, on);
}

void OledDisplayExtravaganza::drawSqr(float xinit,
                                      float yinit,
                                      float points,
                                      bool  on)
{
    DrawLine(xinit, yinit - 4, xinit + 9, yinit - 4, on);
    DrawLine(xinit + 9, yinit - 4, xinit + 9, yinit + 7, on);
    DrawLine(xinit + 9, yinit + 7, xinit + 18, yinit + 7, on);
    OledDisplay::SetCursor(xinit, yinit + 12);
    OledDisplay::WriteString("sqr", Font_6x8, on);
}

void OledDisplayExtravaganza::drawSaw(float xinit,
                                      float yinit,
                                      float points,
                                      bool  on)
{
    DrawLine(xinit, yinit + 6, xinit, yinit - 8, on);
    DrawLine(xinit + 18, yinit + 6, xinit, yinit - 8, on);
    OledDisplay::SetCursor(xinit, yinit + 12);
    OledDisplay::WriteString("saw", Font_6x8, on);
}

void OledDisplayExtravaganza::WaveIcons(int  xinit,
                                        int  yinit,
                                        int  points,
                                        int  selector,
                                        bool on)
{
    int selectorIndex = selector;
    switch(selectorIndex)
    {
        case 0:
            this->drawSine(xinit, yinit, points, on);
            OledDisplay::SetCursor(xinit, yinit + 12);
            OledDisplay::WriteString("sin", Font_6x8, on);
            break;
        case 1:
            this->drawTri(xinit, yinit, points, on);
            OledDisplay::SetCursor(xinit, yinit + 12);
            OledDisplay::WriteString("tri", Font_6x8, on);
            break;

        case 2:
            this->drawSqr(xinit, yinit, points, on);
            OledDisplay::SetCursor(xinit, yinit + 12);
            OledDisplay::WriteString("sqr", Font_6x8, on);
            break;

        case 3:
            this->drawSaw(xinit, yinit, points, on);
            OledDisplay::SetCursor(xinit, yinit + 12);
            OledDisplay::WriteString("saw", Font_6x8, on);
        default: break;
    }
}

void OledDisplayExtravaganza::drawDial(float       x,
                                       float       y,
                                       float       radius,
                                       float       amount,
                                       bool        on,
                                       const char* label)
{
    float factor = 90;
    amount       = (amount * (360 - factor));
    for(int i = 0; i < 2; i++)
    {
        OledDisplay::DrawArc(x, y, radius - (i * 1), 180 + factor, -amount, on);
    }
    OledDisplay::DrawRect(
        x, y - radius * 0.1, x + radius, y + radius, false, true);
    OledDisplay::SetCursor(x, y);
    OledDisplay::WriteString(label, Font_7x10, true);
}


void OledDisplayExtravaganza::drawHorizontalToggle(float       x,
                                                   float       y,
                                                   float       radius,
                                                   bool        on,
                                                   bool        state,
                                                   const char* label)
{
    OledDisplay::DrawArc(x, y, radius, 270, 180, on);
    OledDisplay::DrawArc(x - radius, y, radius, 270, -180, on);
    OledDisplay::DrawLine(x, y - radius, x - radius, y - radius, on);
    OledDisplay::DrawLine(x, y + radius, x - radius, y + radius, on);
    OledDisplay::SetCursor(x - (radius * 1.75), y - (radius * 2.5));
    OledDisplay::WriteString(label, Font_7x10, on);

    if(state == true)
    {
        for(int i = 1; i <= radius; i++)
        {
            OledDisplay::DrawCircle(x, y, (radius / 2) - i, on);
            OledDisplay::DrawCircle(x, y, (radius / 2) - i, on);
            OledDisplay::SetCursor(x - radius * 1.35, y - radius / 3);
            OledDisplay::WriteString("1", Font_6x8, on);
        }
    }
    else
    {
        for(int i = 1; i <= radius; i++)
        {
            OledDisplay::DrawCircle(x - radius, y, (radius / 2) - i, on);
            OledDisplay::DrawCircle(x - radius, y, (radius / 2) - i, on);
            OledDisplay::SetCursor(x - radius * 0.15, y - radius / 3);
            OledDisplay::WriteString("2", Font_6x8, on);
        }
    }
}

void OledDisplayExtravaganza::drawVerticalToggle(float       x,
                                                 float       y,
                                                 float       radius,
                                                 bool        on,
                                                 bool        state,
                                                 const char* label)
{
    OledDisplay::DrawArc(x, y, radius, 0, -180, on);
    OledDisplay::DrawArc(x, y - radius, radius, 0, 180, on);
    OledDisplay::DrawLine(x - radius, y, x - radius, y - radius, on);
    OledDisplay::DrawLine(x + radius, y, x + radius, y - radius, on);
    OledDisplay::SetCursor(x - (radius * 1.75), y - (radius * 2.5));
    OledDisplay::WriteString(label, Font_7x10, on);

    if(state == true)
    {
        for(int i = 1; i <= radius; i++)
        {
            OledDisplay::DrawCircle(x, y, (radius / 2) - i, on);
            OledDisplay::DrawCircle(x, y, (radius / 2) - i, on);
            OledDisplay::SetCursor(x - radius / 4, y - radius * 1.45);
            OledDisplay::WriteString("O", Font_6x8, on);
        }
    }
    else
    {
        for(int i = 1; i <= radius; i++)
        {
            OledDisplay::DrawCircle(
                x, (y - radius) * 0.97, (radius / 2) - i, on);
            OledDisplay::DrawCircle(
                x, (y - radius) * 0.97, (radius / 2) - i, on);
            OledDisplay::SetCursor(x - radius * 0.15, y - radius / 3);
            OledDisplay::WriteString("I", Font_6x8, on);
        }
    }
}