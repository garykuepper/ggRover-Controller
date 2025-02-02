//
// Created by tr0n on 2/1/2025.
//

#include "Xbee.h"


Xbee::Xbee(uint8_t rxPin, uint8_t txPin, int baud)
    : xbeeSerial(rxPin, txPin), baudRate(baud) {}

void Xbee::begin() {
    xbeeSerial.begin(baudRate);
}

void Xbee::send(const String &data) {
    xbeeSerial.print(data);
}

void Xbee::send(const unsigned char* data, size_t length) {
    for (size_t i = 0; i < length; i++) {
        xbeeSerial.write(data[i]);
    }
}

String Xbee::receive() {
    String receivedData = "";
    while (xbeeSerial.available()) {
        receivedData += (char)xbeeSerial.read();
    }
    return receivedData;
}

bool Xbee::available() {
    return xbeeSerial.available();
}

