#ifndef DS4_CONTROLLER_DRIVER_H
#define DS4_CONTROLLER_DRIVER_H

#include <DS4_I2C_CONTROL.h>

class DS4ControllerDriver {
public:
    DS4ControllerDriver(uint8_t address);
    void init();
    void update();
    bool isConnected();
    int getLeftJoystickY();
    int getLeftJoystickX();
    int getRightJoystickY();
    int getRightJoystickX();
    bool getButtonL1();
    bool getL2();
    bool getButtonR1();
    bool getR2();
    bool getButtonX();
    bool getButtonCircle();
    bool getButtonSquare();
    bool getButtonTriangle();

private:
    DS4_I2C_CONTROL ds4;
};

#endif
