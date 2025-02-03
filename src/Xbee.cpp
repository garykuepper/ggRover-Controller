//
// Created by tr0n on 2/1/2025.
//

#include "Xbee.h"

Xbee::Xbee(HardwareSerial &serialPort, int baud)
    : xbeeSerial(serialPort), baudRate(baud) {}

void Xbee::begin()
{
    xbeeSerial.begin(baudRate);
}

void Xbee::send(const String &data)
{
    xbeeSerial.print(data);
}

void Xbee::send(const unsigned char *data, size_t length){
    xbeeSerial.write(data, length)

    //   for (size_t i = 0; i < length; i++) {
    //       xbeeSerial.write(data[i]);
    //    }
}

size_t Xbee::receive(unsigned char *buffer, size_t maxLength)
{
    size_t bytesRead = 0;
    while (xbeeSerial.available() && bytesRead < maxLength)
    {
        buffer[bytesRead++] = xbeeSerial.read();
    }
    return bytesRead;
}

bool Xbee::available()
{
    return xbeeSerial.available();
}
