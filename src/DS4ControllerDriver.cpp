#include "DS4ControllerDriver.h"

DS4ControllerDriver::DS4ControllerDriver(uint8_t address) : ds4(address) {}

void DS4ControllerDriver::init() {
    ds4.begin();
}

void DS4ControllerDriver::update() {
    ds4.get_ps4();
}

bool DS4ControllerDriver::isConnected() {
    return ds4.ps4_ok;
}

int DS4ControllerDriver::getLeftJoystickY() {
    return ds4.l_joystick_y;
}

int DS4ControllerDriver::getLeftJoystickX() {
    return ds4.l_joystick_x;
}

int DS4ControllerDriver::getRightJoystickY() {
    return ds4.r_joystick_y;
}

int DS4ControllerDriver::getRightJoystickX() {
    return ds4.r_joystick_x;
}

bool DS4ControllerDriver::getButtonL1() {
    return ds4.button_l1;
}

bool DS4ControllerDriver::getL2() {
    return ds4.l2;
}

bool DS4ControllerDriver::getButtonR1() {
    return ds4.button_r1;
}

bool DS4ControllerDriver::getR2() {
    return ds4.r2;
}

bool DS4ControllerDriver::getButtonX() {
    return ds4.button_x;
}

bool DS4ControllerDriver::getButtonCircle() {
    return ds4.button_circle;
}

bool DS4ControllerDriver::getButtonSquare() {
    return ds4.button_square;
}

bool DS4ControllerDriver::getButtonTriangle() {
    return ds4.button_triangle;
}
