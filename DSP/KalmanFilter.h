#ifndef KalmanFilter_h
#define KalmanFilter_h

#include "Arduino.h"

class KalmanFilter
{
public:
    KalmanFilter(float initialWeight, float uncertainty, float noise);
    float stateEstimate(float measurement, float uncertainty);
    float uncertainty();
    void reset(float weight, float uncertainty);

private:
    // stateEstimate, KalmanValue, Variance, Noise
    float x, K, p, q;
};
#endif