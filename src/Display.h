//
// Created by tr0n on 1/30/2025.
//

#ifndef DISPLAY_H
#define DISPLAY_H
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SimpleMovingAverage.h>
#include <DS4.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32



class Display
{
public:
    Display();
    void init();
    void showText();
    void showDS4(const DS4 &ds4);

private:
    Adafruit_SSD1306 disp;
    SimpleMovingAverage sma;
};


#endif //DISPLAY_H
