# FDM-Playground
Numerical simulation of magnetic fields in a coil using the Finite Difference Method

This repository contains small experiments with finite difference method.

Goal:
- implement simple grid-based simulations in C++

Focus is consistency and incremental development.

This repo is a side project for small incremental practice.



## Finite Difference Discretization

Grid: $r_i = i \Delta r$, $z_j = j \Delta z$, with $i=0..N_r$, $j=0..N_z$.

Let $A_{i,j} = A_\phi(r_i, z_j)$.

**Central differences** (interior points where $i \ge 1$) for the PDE:

$$
\frac{A_{i+1,j} - 2A_{i,j} + A_{i-1,j}}{\Delta r^2}
+ \frac{1}{r_i} \cdot \frac{A_{i+1,j} - A_{i-1,j}}{2\Delta r}
- \frac{A_{i,j}}{r_i^2}
+ \frac{A_{i,j+1} - 2A_{i,j} + A_{i,j-1}}{\Delta z^2}
= -\mu_0 J_{i,j}
$$

Combine terms to solve for $A_{i,j}$ iteratively:

$$
A_{i,j} = \frac{
\frac{A_{i+1,j} + A_{i-1,j}}{\Delta r^2}
+ \frac{A_{i+1,j} - A_{i-1,j}}{2 r_i \Delta r}
+ \frac{A_{i,j+1} + A_{i,j-1}}{\Delta z^2}
+ \mu_0 J_{i,j}
}{
\frac{2}{\Delta r^2} + \frac{1}{r_i^2} + \frac{2}{\Delta z^2}
}
$$
