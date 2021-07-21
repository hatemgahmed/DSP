
#include "Arduino.h"
#include "AlphaFilter.h"
AlphaFilter::AlphaFilter(int initialWeight, float differenceThreshold)
{
    predictedValue = initialWeight;
    diffThreshold = differenceThreshold;
}
bool AlphaFilter::isReset()
{
    return N == 0;
}
void AlphaFilter::reset()
{
    N = 0;
    predictedValue = 0;
}
float AlphaFilter::stateEstimate(float measurement)
{
    float difference = (measurement - predictedValue);
    if (difference >= diffThreshold || -1 * difference >= diffThreshold)
    {
        N = 0;
        predictedValue = measurement;
    }
    else
    {
        N++;
        predictedValue = predictedValue + (1.0 / N) * difference;
    }
    return predictedValue;
}