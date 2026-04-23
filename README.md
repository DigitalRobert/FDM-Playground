# FDM-Playground
Numerical simulation of magnetic fields in a coil using the Finite Difference Method

This repository contains small experiments with finite difference method.

Goal:
- implement simple grid-based simulations in C++

Focus is consistency and incremental development.

This repo is a side project for small incremental practice.



### Discretized PDE

Using central differences:

$$
\frac{A_{i+1,j} - 2A_{i,j} + A_{i-1,j}}{\Delta r^2}
+ \frac{1}{r_i} \cdot \frac{A_{i+1,j} - A_{i-1,j}}{2\Delta r}
- \frac{A_{i,j}}{r_i^2}
+ \frac{A_{i,j+1} - 2A_{i,j} + A_{i,j-1}}{\Delta z^2}
= -\mu_0 J_{i,j}
$$
