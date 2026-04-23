# Coil Magnetic Field - FDM Simulation
Finite Difference Method

## Status: work in progress

This project will contain:

- theory notes on magnetic field of a simple coil
- analytical reference formulas (Biot-Savart, on-axis field)
- finite difference method (FDM) discretisation
- C++ simulation code

## Physics

Simple circular coil, magnetostatic regime.
Key equation to solve numerically:

$$
B_z(z) = \frac{\mu_0 I R^2}{2(R^2 + z^2)^{3/2}}
$$

## Next steps

- [ ] theory folder with equations
- [ ] FDM grid implementation in C++
- [ ] validation against analytical solution

## Built with

C++ / standard library
