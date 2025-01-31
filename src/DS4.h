//
// Created by tr0n on 1/30/2025.
//

#ifndef DS4_H
#define DS4_H

#include <Arduino.h>
#include <Wire.h>
#define WIRE Wire


#define IC2_LENGTH 14
#define DEFAULT_I2C_ADDRESS 0x29

class DS4 {
public:
    DS4(uint8_t address = DEFAULT_I2C_ADDRESS);
    void begin(void);
    void get_ps4();
    unsigned char* get_ps4_i2c();
    bool ps4_ok;

    unsigned char  l_joystick_x;
    unsigned char  l_joystick_y;
    unsigned char  r_joystick_x;
    unsigned char  r_joystick_y;
    unsigned char  accel_x;
    unsigned char  accel_y;
    unsigned char  l2;
    unsigned char  r2;

    unsigned char  button_left;
    unsigned char  button_down;
    unsigned char  button_right;
    unsigned char  button_up;
    unsigned char  button_square;
    unsigned char  button_x;
    unsigned char  button_circle;
    unsigned char  button_triangle;

    unsigned char  button_l1;
    unsigned char  button_r1;
    unsigned char  button_l2;
    unsigned char  button_r2;
    unsigned char  button_share;
    unsigned char  button_options;
    unsigned char  button_l3;
    unsigned char  button_r3;

    unsigned char  button_ps4;
    unsigned char  button_tpad;

    unsigned char  tpad_x;
    unsigned char  tpad_y;
    unsigned char  battery;

private:
    uint8_t _i2caddr;
    uint8_t _i2clength;
    unsigned char ps4_ic2[IC2_LENGTH];
    void decode_ps4(void);
};



#endif //DS4_H
