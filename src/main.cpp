#include <Arduino.h>//
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Display.h>
#include <DS4.h>

#define DEBUG false
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

unsigned long timer;
uint32_t baudRate = 115200;
uint8_t read_interval = 50;
DS4 ds4;
Display display;


void showStatus();
void showText();
void showDisplay();

void setup()
{
    //while( !Serial ); // sometimes necessary with Teensy 3 or Arduino Micro
    Serial.begin(baudRate);
    timer = 0;
    ds4.begin();

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Don't proceed, loop forever
    }

    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
    display.clearDisplay();
    showText();
}


void loop()
{
    if (millis() > timer)
    {
        // Serial.println("am i working?");
        timer = millis() + read_interval;
        ds4.get_ps4();
        if (DEBUG)
        {
            Serial.println((String)"ps4_ok = " + ds4.ps4_ok);
        }
        if (ds4.ps4_ok)
        {
            showStatus();
            showDisplay();
        }
    }
}

void showText()
{
    display.clearDisplay();

    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println(F("BRO"));
    display.display(); // Show initial text
    delay(100);
}

void showDisplay()
{
    display.clearDisplay();
    display.setTextSize(1); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println((String)"L_Y: " + ds4.l_joystick_y);
    display.setCursor(10, 8);
    display.println((String)"L_X: " + ds4.l_joystick_x);
    display.setCursor(64, 0);
    display.println((String)"R_Y: " + ds4.r_joystick_y);
    display.setCursor(64, 8);
    display.println((String)"R_X: " + ds4.r_joystick_x);
    display.setCursor(10, 16);
    display.println((String)"L1: " + ds4.button_l1);
    display.setCursor(10, 24);
    display.println((String)"L2: " + ds4.l2);
    display.setCursor(64, 16);
    display.println((String)"R1: " + ds4.button_r1);
    display.setCursor(64, 24);
    display.println((String)"R2: " + ds4.r2);
    display.setCursor(120, 0);
    display.println((String)ds4.button_x);
    display.setCursor(120, 8);
    display.println((String)ds4.button_circle);
    display.setCursor(120, 16);
    display.println((String)ds4.button_square);
    display.setCursor(120, 24);
    display.println((String)ds4.button_triangle);
    display.display(); // Show initial text
}

void showStatus()
{
    Serial.println((String)"PS4 left joystick value is x: " + ds4.l_joystick_x + " y: " + ds4.l_joystick_y);
    Serial.println((String)"PS4 right joystick value is x: " + ds4.r_joystick_x + " y: " + ds4.r_joystick_y);
    Serial.println((String)"PS4 R1 button is:  " + ds4.button_r1);
    Serial.println((String)"PS4 R2 button is:  " + ds4.button_r2);
    Serial.println((String)"Buttons: " + ds4.button_square + ds4.button_circle + ds4.button_x + ds4.button_triangle);
}
