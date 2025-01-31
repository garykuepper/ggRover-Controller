#include "SimpleMovingAverage.h"

// Constructor: Initializes the buffer and variables
SimpleMovingAverage::SimpleMovingAverage(int windowSize) {
    N = windowSize;
    readings = new unsigned char[N];  // Allocate memory for the readings array
    readIndex = 0;
    total = 0;
    average = 0;

    // Initialize all readings to 0
    for (int i = 0; i < N; i++) {
        readings[i] = 0;
    }
}

// Destructor: Cleans up allocated memory
SimpleMovingAverage::~SimpleMovingAverage() {
    delete[] readings;  // Free allocated memory
}

// Updates the moving average with a new reading
void SimpleMovingAverage::updateAverage(unsigned char newReading) {
    total = total - readings[readIndex];  // Remove oldest reading from sum
    readings[readIndex] = newReading;     // Store new reading in buffer
    total = total + readings[readIndex];  // Add new reading to sum
    readIndex = (readIndex + 1) % N;      // Wrap index to implement circular buffer

    // Compute the moving average using proper rounding
    float avg = (float)total / (float)N;
    average = (unsigned char)round(avg);  // Use round() to get nearest integer


}

// Returns the current moving average
unsigned char SimpleMovingAverage::getAverage() {
    return average;
}
