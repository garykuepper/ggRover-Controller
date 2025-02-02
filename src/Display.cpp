#include "Display.h"

Display::Display()
{
    disp = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
    sma = SimpleMovingAverage(10);
    bm = BatteryMonitor(A0);
}

void Display::init()
{
    if (!disp.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        while (true);
    }
    disp.display();  // splash screen
    delay(2000);
    disp.clearDisplay();
}

void Display::showText()
{
    disp.clearDisplay();
    disp.setTextSize(2);
    disp.setTextColor(SSD1306_WHITE);
    disp.setCursor(10, 0);
    disp.println(F("Hello, world!"));
    disp.display();
    delay(100);
}

void Display::showDS4(const DS4 &ds4)
{
    sma.updateAverage(ds4.l_joystick_y);
    unsigned char ly = sma.getAverage();
    disp.clearDisplay();
    disp.setTextSize(1); // Draw 2X-scale text
    disp.setTextColor(SSD1306_WHITE);
    disp.setCursor(10, 0);
    disp.println((String)"L_Y: " + ly);
    disp.setCursor(10, 8);
    disp.println((String)"L_X: " + ds4.l_joystick_x);
    disp.setCursor(64, 0);
    disp.println((String)"R_Y: " + ds4.r_joystick_y);
    disp.setCursor(64, 8);
    disp.println((String)"R_X: " + ds4.r_joystick_x);
    disp.setCursor(10, 16);
    disp.println((String)"L1: " + ds4.button_l1);
    disp.setCursor(10, 24);
    disp.println((String)"L2: " + ds4.l2);
    disp.setCursor(64, 16);
    disp.println((String)"R1: " + ds4.button_r1);
    disp.setCursor(64, 24);
    disp.println((String)"R2: " + ds4.r2);
    disp.setCursor(120, 0);
    disp.println((String)ds4.button_x);
    disp.setCursor(120, 8);
    disp.println((String)ds4.button_circle);
    disp.setCursor(120, 16);
    disp.println((String)ds4.button_square);
    disp.setCursor(120, 24);
    disp.println((String)ds4.button_triangle);
    disp.setCursor(64, 32);
    disp.println((String)bm.getBatteryLevel());
    disp.display();
}