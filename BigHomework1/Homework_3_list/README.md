# Main classes

## Polynomial

Polynomial class represents polynom of any degree. Every term for polynomial stored as a
list of Term objects (see description below).

`evaluate` function used to evaluate polynomial in some point X
`sum` function used to add two polynomials of any degree
`mul` function used to multiply two polynomials
`operator<<` is used to output polynomial to standard output stream.


## Term

Term class stores single polynomial term, something like `23.45 * X^5`

`coeff` as double represents single coefficient
`exp` as an int represents single exponent value

`operator<<` is used to output single Term  to standard output stream.


## Input

Polynom value is read from `in.txt` file.