//
// Created by tr0n on 1/30/2025.
//

#ifndef DISPLAY_H
#define DISPLAY_H
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

class Display {
public:
    Display();
    void init();
    void showText(const char* text);
    void showDisplay(int l_y, int l_x, int r_y, int r_x, bool button_l1, bool l2, bool button_r1, bool r2, bool button_x, bool button_circle, bool button_square, bool button_triangle);

private:
    Adafruit_SSD1306 disp();
};



#endif //DISPLAY_H
