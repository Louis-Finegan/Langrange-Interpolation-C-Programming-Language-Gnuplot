# Lagrange Interpolation

Written in Ubuntu 23.04 LTS. This progam was written for GNU/Linux systems.

## Visualize lagrange polynomials with GNU plot

The data points are parsed from a csv file from `data/` directory. From this data 

Lagrange interpolation is a mathematical method that finds new points $(x,y)$ in between known discrete points $(x_k, y_k)$ for $k \in \mathbb{Z}$. These new points are calculated using a polynomial $P_n(x)$ called the *Lagrange Polynomial*. The maximum value for $k$ is $n$, which is the degree of $P_n(x)$. 

The *Lagrange Polynomial* is written in the following form:

$$P_n(x) = y_0L_0(x) + y_1L_1(x) + \dots + y_nL_n(x)$$

Where $L_k(x)$ is called the *Lagrange Basis*, and is written as such

$$L_i(x) = \frac{x - x_0}{x_i - x_0} \dots \frac{x - x_{i-1}}{x_i - x_{i-1}}\frac{x - x_{i+1}}{x_i - x_{i+1}} \dots \frac{x - x_n}{x_i - x_n} $$

For $n$ known points, or node, valuev pairs, then the lagrange basis would be composed of $n$ basis vectors (Lagrange Basis).



This repository hosts a C program specifically engineered for Lagrange interpolation. It efficiently processes data points extracted from a CSV file, employing robust algorithms to compute the interpolating polynomial. Subsequently, it utilizes the GNU Plot library to visualize the interpolated results comprehensively.


Perform lagrange interpolation on data point stored in csv files. Project is written in the c programming language.

[ADD IMAGE HERE]

**Ensure GNU plot is installed on your machine.** otherwise run

```
sudo apt-get update \
sudo apt-get install gnuplot
```

## Formulation


## How to use

Clone the repository

```
git clone Louis-Finegan/Lagrange-Interpolation-C- \
make
```

To run the executible 

## License

MIT License - see LICENSE for details.