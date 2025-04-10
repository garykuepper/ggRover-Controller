#include "Xbee.h"

Xbee::Xbee(Stream &serialPort, int baud, bool initSerial)
    : xbeeSerial(serialPort), baudRate(baud), shouldInit(initSerial) {}

void Xbee::begin() {
    if (shouldInit) {
        // Call begin() only if using HardwareSerial
        ((HardwareSerial*)&xbeeSerial)->begin(baudRate);
    }
}

void Xbee::send(const String &data) {
    xbeeSerial.print(data);
}

void Xbee::send(const unsigned char *data, size_t length) {
    xbeeSerial.write(data, length);
}

size_t Xbee::receive(unsigned char *buffer, size_t maxLength) {
    size_t bytesRead = 0;
    while (xbeeSerial.available() && bytesRead < maxLength) {
        buffer[bytesRead++] = xbeeSerial.read();
    }

    if (bytesRead > 0) {
        Serial.print("Received: ");
        for (size_t i = 0; i < bytesRead; i++) {
            Serial.write(buffer[i]);
        }
        Serial.println();
    }

    return bytesRead;
}

String Xbee::receiveString(char terminator) {
    String receivedData = "";
    while (xbeeSerial.available()) {
        char c = xbeeSerial.read();
        if (c == terminator) break;
        receivedData += c;
    }

    if (receivedData.length() > 0) {
        Serial.print("Received String: ");
        Serial.println(receivedData);
    }

    return receivedData;
}

bool Xbee::available() {
    return xbeeSerial.available();
}
