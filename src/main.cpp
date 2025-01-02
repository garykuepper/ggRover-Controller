#include <Arduino.h>//
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DS4_I2C_CONTROL.h>


#define DEBUG false
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

unsigned long timer;
uint32_t baudRate = 115200;
uint8_t read_interval = 20;
DS4_I2C_CONTROL ds4 = DS4_I2C_CONTROL(0x29);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void showstatus(void);
void showtext();


void setup()
{
    // while( !Serial ); // sometimes necessary with Teensy 3 or Arduino Micro
    //Serial.begin(baudRate);
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
}


void loop()
{
    if (millis() > timer)
    {
        timer = millis() + read_interval;
        ds4.get_ps4();
        if (DEBUG)
        {
            //Serial.println((String)"ps4_ok = " + ds4.ps4_ok);
        }
        if (ds4.ps4_ok)
        {
            showStatus();
        }
    }
}

void showtext()
{
    display.clearDisplay();

    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println(F("scroll"));
    display.display(); // Show initial text
    delay(100);
}

void showStatus()
{
    Serial.println((String)"PS4 left joystick value is x: " + ds4.l_joystick_x + " y: " + ds4.l_joystick_y);
    Serial.println((String)"PS4 right joystick value is x: " + ds4.r_joystick_x + " y: " + ds4.r_joystick_y);
    Serial.println((String)"PS4 R1 button is:  " + ds4.button_r1);
    Serial.println((String)"PS4 R2 button is:  " + ds4.button_r2);
}
