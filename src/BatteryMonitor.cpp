//
// Created by tr0n on 2/1/2025.
//

#include "BatteryMonitor.h"


BatteryMonitor::BatteryMonitor(int pin, double vRef)
    : analogPin(pin), referenceVoltage(vRef)
{


}

void BatteryMonitor::init()
{
    pinMode(analogPin, INPUT);
    // Initialize the battery monitor
}
int BatteryMonitor::getRaw()
{
    // Get the raw analog value
    return analogRead(analogPin);
}
double BatteryMonitor::getBatteryLevel()
{
    // Get the current battery level
    int analogValue = analogRead(analogPin);
    return (analogValue * referenceVoltage) / analogMax;


}

double BatteryMonitor::getBatteryPercentage() {
    double voltage = getBatteryLevel();
    double minVoltage = 3.0;  // Discharged threshold
    double maxVoltage = 4.2;  // Fully charged threshold

    double percentage = ((voltage - minVoltage) / (maxVoltage - minVoltage)) * 100.0;
    return constrain(percentage, 0.0, 100.0); // Keep within 0-100%
}