//
// Created by tr0n on 2/1/2025.
//

#ifndef XBEE_H
#define XBEE_H

#include <Arduino.h>


class Xbee {
private:
    HardwareSerial &xbeeSerial;
    int baudRate;

public:
    Xbee(HardwareSerial &serialPort = Serial1, int baud = 57600);
    void begin();
    void send(const String &data);
    void send(const unsigned char* data, size_t length);
    size_t receive(unsigned char* buffer, size_t maxLength);  // New function
    bool available();
};



#endif //XBEE_H
