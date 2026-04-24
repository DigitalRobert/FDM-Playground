# Coil Magnetic Field — Formula Reference

2D problem in (r, z) half-plane — azimuthal symmetry assumed.

---

## Biot-Savart Law

Magnetic field from a current element:

$$
d\mathbf{B} = \frac{\mu_0 I}{4\pi} \frac{d\vec{\ell} \times \hat{r}}{r^2}
$$

---

## On-Axis Field (closed form)

Field along symmetry axis at distance z from loop centre:

$$
B_z(z) = \frac{\mu_0 I R^2}{2(R^2 + z^2)^{3/2}}
$$

At centre z = 0:

$$
B_0 = \frac{\mu_0 I}{2R}
$$

---

## Vector Potential

B field expressed via vector potential A:

$$
\mathbf{B} = \nabla \times \mathbf{A}
$$

For azimuthal symmetry only A_phi component survives:

$$
B_r = -\frac{\partial A_\phi}{\partial z}
\qquad
B_z = \frac{1}{r}\frac{\partial (r A_\phi)}{\partial r}
$$

---

## Poisson Equation (what FDM solves)

$$
\nabla^2 A_\phi - \frac{A_\phi}{r^2} = -\mu_0 J_\phi
$$

Note: the extra term A_phi / r^2 comes from cylindrical coordinates — not present in Cartesian.

---

## FDM Discretisation on 2D Grid

Grid indices: i along r, j along z. Spacing: delta_r, delta_z.

$$
\frac{A_{i+1,j} - 2A_{i,j} + A_{i-1,j}}{\Delta r^2}
+ \frac{1}{r_i}\frac{A_{i+1,j} - A_{i-1,j}}{2\,\Delta r}
- \frac{A_{i,j}}{{r_i}^2}
+ \frac{A_{i,j+1} - 2A_{i,j} + A_{i,j-1}}{\Delta z^2}
= -\mu_0 J_\phi
$$

---

## Validation Reference — Off-Axis (elliptic integrals)

$$
k^2 = \frac{4 R\,\rho}{(R+\rho)^2 + z^2}
$$

$$
B_z = \frac{\mu_0 I}{2\pi\,\alpha^2}
\left[ K(k) + \frac{R^2 - \rho^2 - z^2}{(R-\rho)^2 + z^2} E(k) \right]
$$

$$
\alpha^2 = (R + \rho)^2 + z^2
$$

K(k), E(k) — complete elliptic integrals, available in C++17:
`std::comp_ellint_1(k)` and `std::comp_ellint_2(k)`

---

## Constants

| Symbol   | Value                        | Unit   |
|----------|------------------------------|--------|
| mu_0     | 4π × 10⁻⁷                   | T·m/A  |
| I        | current in loop              | A      |
| R        | loop radius                  | m      |
| z        | axial distance from centre   | m      |
| rho (r)  | radial distance from axis    | m      |
| A_phi    | vector potential, phi component | T·m |
| J_phi    | current density, phi component  | A/m² |

---

*Reference file — companion to C++ FDM simulation (next sessions)*
