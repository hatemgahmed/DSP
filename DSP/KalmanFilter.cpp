#include "Arduino.h"
#include "KalmanFilter.h"
KalmanFilter::KalmanFilter(float initialWeight, float uncertainty, float noise)
{
    x = initialWeight;
    p = uncertainty * uncertainty;
    q = noise;
}
float KalmanFilter::stateEstimate(float measurement, float uncertainty)
{
    p = p + q;
    K = p / (p + uncertainty * uncertainty);
    x = x + K * (measurement - x);
    p = (1 - K) * p;
    return x;
}
float KalmanFilter::uncertainty()
{
    return float(sqrt(p));
}
void KalmanFilter::reset(float weight, float uncertainty)
{
    x = weight;
    p = uncertainty;
}