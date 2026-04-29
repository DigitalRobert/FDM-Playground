#pragma once

// Physical constants
namespace constants {
    constexpr double mu0 = 4.0 * 3.14159265358979323846e-7;  // T·m/A
}

// Returns B_z [Tesla] on the symmetry axis at axial distance z [m]
// from a circular loop of radius R [m] carrying current I [A].
// Formula: B_z = (mu0 * I * R^2) / (2 * (R^2 + z^2)^(3/2))
double bz_on_axis(double I, double R, double z);
