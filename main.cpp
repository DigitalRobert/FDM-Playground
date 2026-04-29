#include "coil_field.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

int main()
{
    // Coil parameters
    const double I = 1.0;    // current [A]
    const double R = 0.05;   // radius 5 cm [m]

    // Analytical centre value — useful to cross-check the table
    double B0 = constants::mu0 * I / (2.0 * R);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Loop: I = " << I << " A,  R = " << R * 100 << " cm\n";
    std::cout << "B0 (centre, analytical) = " << B0 * 1e3 << " mT\n\n";

    // Print table header
    std::cout << std::setw(12) << "z [cm]"
              << std::setw(14) << "Bz [mT]"
              << std::setw(16) << "Bz / B0"
              << "\n";
    std::cout << std::string(42, '-') << "\n";

    // Scan z from 0 to 3R in small steps
    int steps = 20;
    double z_max = 3.0 * R;

    for (int n = 0; n <= steps; ++n) {
        double z = z_max * n / steps;
        double Bz = bz_on_axis(I, R, z);

        std::cout << std::setw(12) << z * 100          // convert to cm
                  << std::setw(14) << Bz * 1e3         // convert to mT
                  << std::setw(16) << Bz / B0
                  << "\n";
    }

    return 0;
}
