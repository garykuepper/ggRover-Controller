#include <Arduino.h>
#include "DisplayDriver.h"
#include "DS4ControllerDriver.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

DisplayDriver displayDriver(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_RESET, SCREEN_ADDRESS);
DS4ControllerDriver ds4(0x29);

void setup()
{
    Serial.begin(115200);
    displayDriver.init();
    ds4.init();
    displayDriver.showText("BRO");
}

void loop()
{
    ds4.update();
    if (ds4.isConnected())
    {
        displayDriver.showDisplay(
            ds4.getLeftJoystickY(),
            ds4.getLeftJoystickX(),
            ds4.getRightJoystickY(),
            ds4.getRightJoystickX(),
            ds4.getButtonL1(),
            ds4.getL2(),
            ds4.getButtonR1(),
            ds4.getR2(),
            ds4.getButtonX(),
            ds4.getButtonCircle(),
            ds4.getButtonSquare(),
            ds4.getButtonTriangle()
        );
    }
}
