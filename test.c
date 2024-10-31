#include "bisection.h"
#include <assert.h>
#include <math.h>

// Функція для обчислення різниці між f(x) = a1 * x^3 та g(x) = a2 * x^2 + b
double intersection_test_function(double x, double a1, double a2, double b) {
  return a1 * pow(x, 3) - (a2 * pow(x, 2) + b);
}


double a1_test, a2_test, b_test;

double test_func(double x) {
  return intersection_test_function(x, a1_test, a2_test, b_test);
}

void test_bisection(double a1, double a2, double b) {
  double tol = 1e-6;
  int max_iter = 1000;
  double a = -10.0, b_interval = 10.0;

  a1_test = a1;
  a2_test = a2;
  b_test = b;

  double root = bisection(test_func, a, b_interval, tol, max_iter);

  assert(fabs(test_func(root)) < tol);
}

void run_tests() {
  test_bisection(1.0, 2.0, 3.0);
  printf("Усі тести пройдено успішно.\n");
}
