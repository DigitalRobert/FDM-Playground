# FDM-Playground
Numerical simulation of magnetic fields in a coil using the Finite Difference Method

This repository contains small experiments with finite difference method.

Goal:
- implement simple grid-based simulations in C++

Focus is consistency and incremental development.

This repo is a side project for small incremental practice.

# FDM Discretisation (preview)

The Poisson equation to be solved:

$$
\nabla^2 A_\phi = -\mu_0 J_\phi
$$

Discretised on a 2D grid (r, z half-plane):

$$
\frac{A_{i+1,j} - 2A_{i,j} + A_{i-1,j}}{\Delta r^2} 
+ \frac{A_{i,j+1} - 2A_{i,j} + A_{i,j-1}}{\Delta z^2} 
= -\mu_0 J_\phi
$$

- `i, j` — grid indices in r and z direction  
- `delta_r`, `delta_z` — grid spacing  
- `A_phi` — azimuthal component of vector potential  
- `J_phi` — current density of the coil
