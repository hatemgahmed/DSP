// Chebyshev High Pass 2nd order ripple = -3db
// sample rate = 100hz
// lower corner = 5;
// type float
// url: http://www.schwietering.com/jayduino/filtuino/

#ifndef ChebyshevHighPass_h
#define ChebyshevHighPass_h

#include "Arduino.h"

class ChebyshevHighPass
{
public:
    ChebyshevHighPass();
    float filter(float x);
    void reset();

private:
    float v[3];
};

#endif