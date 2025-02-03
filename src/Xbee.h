#ifndef XBEE_H
#define XBEE_H

#include <Arduino.h>
#include <Stream.h>  // Base class for both HardwareSerial and SoftwareSerial

class Xbee {
private:
    Stream &xbeeSerial;
    int baudRate;
    bool shouldInit;  // Flag to control whether we call begin()

public:
    Xbee(Stream &serialPort, int baud = 57600, bool initSerial = false);  // Add initSerial flag
    void begin();
    void send(const String &data);
    void send(const unsigned char* data, size_t length);
    size_t receive(unsigned char* buffer, size_t maxLength);
    String receiveString(char terminator = '\n');
    bool available();
};

#endif // XBEE_H
