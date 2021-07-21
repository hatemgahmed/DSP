// Chebyshev High Pass 2nd order ripple = -3db
// sample rate = 100hz
// lower corner = 10;
// type float
// url: http://www.schwietering.com/jayduino/filtuino/

#include "Arduino.h"
#include "ChebyshevHighPass.h"

ChebyshevHighPass::ChebyshevHighPass()
{
    v[0] = 0.0;
    v[1] = 0.0;
}
void ChebyshevHighPass::reset()
{
    v[0] = 0.0;
    v[1] = 0.0;
}
float ChebyshevHighPass::filter(float x) //class II
{
    v[0] = v[1];
    v[1] = v[2];
    v[2] = (6.919896761595448753e-1 * x) + (-0.59036546147051216504 * v[0]) + (1.17759324316766700314 * v[1]);
    return (v[0] + v[2]) - 2 * v[1];
}