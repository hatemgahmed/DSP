#ifndef AlphaFilter_h
#define AlphaFilter_h

#include "Arduino.h"

class AlphaFilter
{
public:
    AlphaFilter(int initialWeight, float differenceThreshold);
    float stateEstimate(float measurement);
    bool isReset();
    void reset();

private:
    int N = 0;
    float predictedValue, diffThreshold;
};
#endif