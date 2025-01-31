#include "Display.h"

Display::Display()
{
    disp(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
}

void Display::init() {
    if (!disp.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        while (true);
    }
    disp.display();  // splash screen
    delay(2000);
    disp.clearDisplay();
}

void Display::showText(const char* text) {
    disp.clearDisplay();
    disp.setTextSize(2);
    disp.setTextColor(SSD1306_WHITE);
    disp.setCursor(10, 0);
    disp.println(text);
    disp.display();
    delay(100);
}

void Display::showDisplay(int l_y, int l_x, int r_y, int r_x, bool button_l1, bool l2, bool button_r1, bool r2, bool button_x, bool button_circle, bool button_square, bool button_triangle) {
    disp.clearDisplay();
    disp.setTextSize(1);
    disp.setTextColor(SSD1306_WHITE);
    disp.setCursor(10, 0);
    disp.println((String)"L_Y: " + l_y);
    disp.setCursor(10, 8);
    disp.println((String)"L_X: " + l_x);
    disp.setCursor(64, 0);
    disp.println((String)"R_Y: " + r_y);
    disp.setCursor(64, 8);
    disp.println((String)"R_X: " + r_x);
    disp.setCursor(10, 16);
    disp.println((String)"L1: " + button_l1);
    disp.setCursor(10, 24);
    disp.println((String)"L2: " + l2);
    disp.setCursor(64, 16);
    disp.println((String)"R1: " + button_r1);
    disp.setCursor(64, 24);
    disp.println((String)"R2: " + r2);
    disp.setCursor(120, 0);
    disp.println((String)button_x);
    disp.setCursor(120, 8);
    disp.println((String)button_circle);
    disp.setCursor(120, 16);
    disp.println((String)button_square);
    disp.setCursor(120, 24);
    disp.println((String)button_triangle);
    disp.display();
}