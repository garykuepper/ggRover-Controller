//
// Created by tr0n on 2/1/2025.
//

#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <Arduino.h>

class BatteryMonitor {
public:

    void init();
    float getBatteryLevel();
    BatteryMonitor(int pin);


private:
    int analogPin;

};



#endif //BATTERYMONITOR_H
