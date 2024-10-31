#ifndef BISECTION_H
#define BISECTION_H

// Bisection function declaration
double bisection(double (*func)(double), double a, double b, double tol, int max_iter);

#endif
