#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



class DisplayDriver {
public:
    DisplayDriver(int width, int height, int resetPin, int address);
    void init();
    void showText(const char* text);
    void showDisplay(int l_y, int l_x, int r_y, int r_x, bool button_l1, bool l2, bool button_r1, bool r2, bool button_x, bool button_circle, bool button_square, bool button_triangle);
    
private:
    Adafruit_SSD1306 display;
};

#endif