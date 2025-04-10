//
// Created by tr0n on 2/1/2025.
//

#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <Arduino.h>

class BatteryMonitor
{
public:
    void init();
    double getBatteryLevel();
    int getRaw();
    BatteryMonitor(int pin, double vRef = 5.0);
    double getBatteryPercentage();

private:
    int analogPin;
    double referenceVoltage;
    const int analogMax = 1023;
};

#endif // BATTERYMONITOR_H
