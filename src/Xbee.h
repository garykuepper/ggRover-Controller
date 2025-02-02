//
// Created by tr0n on 2/1/2025.
//

#ifndef XBEE_H
#define XBEE_H

#include <Arduino.h>
#include <SoftwareSerial.h>


class Xbee {
private:
    SoftwareSerial xbeeSerial;
    int baudRate;

public:
    Xbee(uint8_t rxPin, uint8_t txPin, int baud = 57600);
    void begin();
    void send(const String &data);
    void send(const unsigned char* data, size_t length);
    size_t receive(unsigned char* buffer, size_t maxLength);  // New function
    bool available();
};



#endif //XBEE_H
