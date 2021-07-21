// Chebyshev Low Pass 2nd order ripple = -3db
// sample rate = 100hz
// lower corner = 5;
// type float
// url: http://www.schwietering.com/jayduino/filtuino/

#ifndef ChebyshevLowPass_h
#define ChebyshevLowPass_h

#include "Arduino.h"

class ChebyshevLowPass
{
public:
    ChebyshevLowPass();
    float filter(float x);
    void reset();

private:
    float v[3];
};

#endif