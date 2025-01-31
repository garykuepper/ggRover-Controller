#include <Arduino.h>
#include "DisplayDriver.h"
#include "DS4Control.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

DisplayDriver displayDriver(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_RESET, SCREEN_ADDRESS);
DS4_I2C_CONTROL ds4(0x29);
int timer = 0;
int read_interval = 100;


void setup()
{
    //Serial.begin(115200);
    displayDriver.init();
    ds4.begin();

}

void loop()
{
    if (millis() > timer)
    {
        // Serial.println("am i working?");
        timer = millis() + read_interval;
        ds4.get_ps4();

        if (ds4.ps4_ok)
        {
            showStatus();
            showDisplay();
        }
    }
}
