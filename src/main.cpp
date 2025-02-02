#include <Arduino.h>
#include <Display.h>
#include <DS4.h>


unsigned long timer;
uint8_t read_interval = 10;
DS4 ds4;
Display display;

void setup()
{
    timer = 0;
    ds4.begin();
    display.init();
}

void loop()
{
    if (millis() > timer)
    {
        

        timer = millis() + read_interval;
        ds4.get_ps4();
        if (ds4.ps4_ok)
        {
            //display.showText();
            display.showDS4(ds4);
        }

    }
}

