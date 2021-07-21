// Chebyshev Low Pass 2nd order ripple = -3db
// sample rate = 100hz
// lower corner = 5;
// type float
// url: http://www.schwietering.com/jayduino/filtuino/

#include "Arduino.h"
#include "ChebyshevLowPass.h"

ChebyshevLowPass::ChebyshevLowPass()
{
    v[0] = 0.0;
    v[1] = 0.0;
}
void ChebyshevLowPass::reset()
{
    v[0] = 0.0;
    v[1] = 0.0;
}
float ChebyshevLowPass::filter(float x) //class II
{
    v[0] = v[1];
    v[1] = v[2];
    v[2] = (1.585792904611480272e-2 * x) + (-0.81758738489617932554 * v[0]) + (1.75415566871172012853 * v[1]);
    return (v[0] + v[2]) + 2 * v[1];
}