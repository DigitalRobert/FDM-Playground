# FDM-Playground
Numerical simulation of magnetic fields in a coil using the Finite Difference Method

This repository contains small experiments with finite difference method.

Goal:
- implement simple grid-based simulations in C++

Focus is consistency and incremental development.

This repo is a side project for small incremental practice.



## Finite Difference Discretization

We define a structured grid in cylindrical coordinates:

- Radial direction: $r_i = i \Delta r$
- Axial direction: $z_j = j \Delta z$

for $i = 0, \dots, N_r$ and $j = 0, \dots, N_z$.

Let the unknown be:

$$
A_{i,j} = A_\phi(r_i, z_j)
$$

---

### Discretized PDE

Using central differences (for interior points with $i \ge 1$):

$$
\frac{A_{i+1,j} - 2A_{i,j} + A_{i-1,j}}{\Delta r^2}
+ \frac{1}{r_i} \cdot \frac{A_{i+1,j} - A_{i-1,j}}{2\Delta r}
- \frac{A_{i,j}}{r_i^2}
+ \frac{A_{i,j+1} - 2A_{i,j} + A_{i,j-1}}{\Delta z^2}
= -\mu_0 J_{i,j}
$$

---

### Iterative Update Formula

Rearranging the equation, we obtain an explicit update rule:

$$
A_{i,j} =
\frac{
\frac{A_{i+1,j} + A_{i-1,j}}{\Delta r^2}
+ \frac{A_{i+1,j} - A_{i-1,j}}{2 r_i \Delta r}
+ \frac{A_{i,j+1} + A_{i,j-1}}{\Delta z^2}
+ \mu_0 J_{i,j}
}{
\frac{2}{\Delta r^2} + \frac{1}{r_i^2} + \frac{2}{\Delta z^2}
}
$$
