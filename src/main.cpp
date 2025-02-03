#include <Arduino.h>
#include <Display.h>
#include <DS4.h>
#include <Xbee.h>

unsigned long timer;
uint8_t read_interval = 10;
DS4 ds4;
Display display;
BatteryMonitor bm(A0, 5.0);
Xbee xbee(Serial1, 57600);

void setup()
{
    timer = 0;
    ds4.begin();
    display.init();
    xbee.begin();
}

void loop()
{
    if (millis() > timer)
    {

        timer = millis() + read_interval;

        uint8_t batteryPercentage = static_cast<uint8_t>(bm.getBatteryPercentage());
        xbee.send(&batteryPercentage, sizeof(batteryPercentage));

        ds4.get_ps4();
        
        if (ds4.ps4_ok)
        {
            // display.showText();
            display.showDS4(ds4, bm);
            
        }
    }
}
