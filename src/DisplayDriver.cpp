#include "DisplayDriver.h"

DisplayDriver::DisplayDriver(int width, int height, int resetPin, int address)
    : display(width, height, &Wire, resetPin)
{
}

void DisplayDriver::init() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        while (true);
    }
    display.display();
    delay(2000);
    display.clearDisplay();
}

void DisplayDriver::showText(const char* text) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println(text);
    display.display();
    delay(100);
}

void DisplayDriver::showDisplay(int l_y, int l_x, int r_y, int r_x, bool button_l1, bool l2, bool button_r1, bool r2, bool button_x, bool button_circle, bool button_square, bool button_triangle) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println((String)"L_Y: " + l_y);
    display.setCursor(10, 8);
    display.println((String)"L_X: " + l_x);
    display.setCursor(64, 0);
    display.println((String)"R_Y: " + r_y);
    display.setCursor(64, 8);
    display.println((String)"R_X: " + r_x);
    display.setCursor(10, 16);
    display.println((String)"L1: " + button_l1);
    display.setCursor(10, 24);
    display.println((String)"L2: " + l2);
    display.setCursor(64, 16);
    display.println((String)"R1: " + button_r1);
    display.setCursor(64, 24);
    display.println((String)"R2: " + r2);
    display.setCursor(120, 0);
    display.println((String)button_x);
    display.setCursor(120, 8);
    display.println((String)button_circle);
    display.setCursor(120, 16);
    display.println((String)button_square);
    display.setCursor(120, 24);
    display.println((String)button_triangle);
    display.display();
}
