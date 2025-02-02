//
// Created by tr0n on 1/30/2025.
//

#ifndef SIMPLEMOVINGAVERAGE_H
#define SIMPLEMOVINGAVERAGE_H

#include <math.h>

class SimpleMovingAverage {

private:
    double *readings;  // Dynamically allocated array to store readings
    int N;                    // Window size (number of samples)
    int readIndex;            // Index for circular buffer
    double total;               // Running sum of the readings
    double average;    // The current moving average (rounded)

public:
    // Constructor: Initializes the moving average with a given window size
    SimpleMovingAverage(int windowSize);

    // Destructor: Cleans up allocated memory
    ~SimpleMovingAverage();

    // Updates the moving average with a new reading
    void updateAverage(double newReading);

    // Returns the current moving average
    double getAverage();
};




#endif //SIMPLEMOVINGAVERAGE_H
