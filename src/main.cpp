#include <Arduino.h>
#include <Display.h>
#include <DS4.h>
#include <Xbee.h>
#include <SoftwareSerial.h>
#include <BatteryMonitor.h>

#define RX_PIN 9
#define TX_PIN 8

SoftwareSerial softSerial(RX_PIN, TX_PIN); // RX, TX

unsigned long timer;
uint8_t read_interval = 100;
DS4 ds4;
Display display;
BatteryMonitor bm(A0, 5.0);
Xbee xbee(softSerial, 57600);

// Timer Variables
unsigned long lastReadTime = 0;
unsigned long lastSendTime = 0;
unsigned long lastReceiveTime = 0;

const unsigned long readInterval = 100;    // Read controller data every 100ms
const unsigned long sendInterval = 2000;   // Send data every 2 seconds
const unsigned long receiveInterval = 500; // Check for incoming data every 500ms

void setup()
{
    timer = 0;
    ds4.begin();
    display.init();
    xbee.begin();
    Serial.begin(9600);
    softSerial.begin(57600);
}

void loop()
{
    unsigned long currentTime = millis();

    // ✅ 1. Read DS4 Data Every 100ms
    if (currentTime - lastReadTime >= readInterval)
    {
        lastReadTime = currentTime;
        ds4.get_ps4();

        if (ds4.ps4_ok)
        {
            display.showDS4(ds4, bm);
        }
    }

    // ✅ 2. Send Data Every 2 Seconds
    if (currentTime - lastSendTime >= sendInterval)
    {
        lastSendTime = currentTime;
        String msg = "Hello World";
        if (xbee.send(msg))
        {
            Serial.println("Sent: " + msg);
        }
        else
        {
            Serial.println("Error: Failed to send message.");
        }
    }

    // ✅ 3. Receive Data Every 0.5 Seconds
    if (currentTime - lastReceiveTime >= receiveInterval)
    {
        lastReceiveTime = currentTime;

        if (xbee.available())
        {
            String receivedMsg = xbee.receiveString();
            if (receivedMsg.length() > 0)
            {
                Serial.print("Received: ");
                Serial.println(receivedMsg);
            }
            else
            {
                Serial.println("Error: Received empty message.");
            }
        }
        else
        {
            Serial.println("No data available from Xbee.");
        }
    }
}
