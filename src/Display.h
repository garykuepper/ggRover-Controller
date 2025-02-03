//
// Created by tr0n on 1/30/2025.
//

#ifndef DISPLAY_H
#define DISPLAY_H
#include <Adafruit_GFX.h>
#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <DS4.h>
#include <BatteryMonitor.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

class Display
{
public:
    Display();
    void init();
    void showText();
    void showDS4(const DS4 &ds4, BatteryMonitor &bm);
    void showSplashScreen();

private:
    Adafruit_SSD1306 disp;
    int lineHeight = 10;
    static const unsigned char ggbytesSplash[];
};

#endif // DISPLAY_H
