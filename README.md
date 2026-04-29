# Coil Magnetic Field — FDM Simulator

A C++ project computing the magnetic field of a circular current loop,
built step by step as a hands-on way to revisit the Finite Difference Method.

Status: work in progress

---

## What this project contains

- theory notes and analytical reference formulas (Biot-Savart, on-axis field)
- finite difference method (FDM) discretisation in 2D cylindrical coordinates
- C++ simulation code built session by session
- validation against analytical solutions

## Physics

Simple circular coil, magnetostatic regime, azimuthal symmetry assumed.
The vector potential A_phi is solved numerically on a 2D (r, z) grid.

On-axis field (closed form, Session 01):

    Bz(z) = mu0 * I * R^2 / ( 2 * (R^2 + z^2)^(3/2) )

## Build

    g++ -std=c++17 -Wall main.cpp coil_field.cpp -o coil

## Next steps

- FDM grid implementation in C++
- off-axis field via elliptic integrals (validation reference)
- comparison: FDM result vs analytical

## Built with

C++ / standard library (C++17)
