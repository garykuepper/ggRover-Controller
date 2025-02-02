//
// Created by tr0n on 2/1/2025.
//

#include "BatteryMonitor.h"


BatteryMonitor::BatteryMonitor(int pin) {
    analogPin = pin;

}

void BatteryMonitor::init()
{

    // Initialize the battery monitor
}

float BatteryMonitor::getBatteryLevel()
{
    // Get the current battery level
    int analogValue = analogRead(analogPin);
    return analogValue / 1023.0;


}