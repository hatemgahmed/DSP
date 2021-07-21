
#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trigPin, int echoPin) : alpha(0, 10)
{
    trig = trigPin;
    echo = echoPin;
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    // attachInterrupt(echo, &Echo, RISING);
}
float Ultrasonic::distance()
{
    if (ready)
    {
        return dist;
    }
    else
    {
        //Not ready, then return an error
        return -1;
    }
}
void Ultrasonic::Trig()
{
    pinSetFast(trig);
    delayMicroseconds(10);
    pinResetFast(trig);
}
void Ultrasonic::Echo()
{
    // Check if it is high
    if (pinReadFast(echo))
    {
        //start calculating high time
        timeLastUpdate = micros();
    }
    else
    {
        dist = alpha.stateEstimate((micros() - timeLastUpdate) * ((340.0f * 100.0 * 0.000001f) / 2.0f));
        ready = true;
    }
}
void Ultrasonic::init()
{
    pinMode(trig, INPUT);
    pinMode(echo, OUTPUT);
}
void Ultrasonic::reset()
{
    alpha.reset();
}