#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"
#include <Signal_Manipulation/AlphaFilter.h>

class Ultrasonic
{
public:
    Ultrasonic(int trigPin, int echoPin);
    void read();
    void reset();
    void Trig();
    void Echo();
    void init();
    float distance();
    volatile float dist;

private:
    AlphaFilter alpha;
    unsigned long timeLastUpdate;
    int echo, trig;
    volatile bool ready;
};
#endif