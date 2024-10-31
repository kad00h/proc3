#include <stdio.h>
#include <math.h>
#include "bisection.h"

// Function f(x) = a1 * x^3 - (a2 * x^2 + b)
double intersection_function(double x, double a1, double a2, double b) {
    return a1 * pow(x, 3) - (a2 * pow(x, 2) + b);
}

// Wrapper to fit the bisection method interface
double wrapper_func(double x) {
    extern double a1, a2, b;
    return intersection_function(x, a1, a2, b);
}

double a1, a2, b;  // Global coefficients for the wrapper function

int main() {
    double a, b_interval, tol;
    int max_iter;

    // Prompting user for input
    printf("Enter the coefficients a1, a2, and b: ");
    scanf("%lf %lf %lf", &a1, &a2, &b);

    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b_interval);

    printf("Enter the tolerance: ");
    scanf("%lf", &tol);

    printf("Enter the maximum iterations: ");
    scanf("%d", &max_iter);

    // Call the bisection method
    double root = bisection(wrapper_func, a, b_interval, tol, max_iter);

    // Print the result
    printf("Intersection found at x = %lf\n", root);

    return 0;
}
