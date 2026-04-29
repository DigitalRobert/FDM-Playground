#include "coil_field.h"
#include <cmath>

double bz_on_axis(double I, double R, double z)
{
    double denom = std::pow(R * R + z * z, 1.5);
    return (constants::mu0 * I * R * R) / (2.0 * denom);
}
