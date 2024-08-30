/**
 * @file metodo-das-cordas.cpp
 * @author Carolina de Souza Freitas (2118784)
 * @author Carlos Sergio Fernandes Junior (2157633)
 * @author Gustavo Soatto Santos (2141790)
 * @author Matheus Paulino Ribeiro (2143432)
 * @author Nicolas Fagundes Scarpa (2093087)
 * @brief
 * @version 0.1
 * @date 2024-08-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double function_x(long double x)
{
  return (2 * pow(x, 2)) + sin(x) - 10;
}

long double function_x_2(long double x)
{
  return (4 - sin(x));
}

void set_c_xn(long double a, long double b, long double *c, long double *xn, long double error)
{
  long double f_a = function_x(a) * function_x_2(a);
  long double f_b = function_x(b) * function_x_2(b);

  if ((f_a) > error)
  {
    *c = a;
    *xn = b;
  }
  else if ((f_b) > error)
  {
    *c = b;
    *xn = a;
  }
}

long double xn_(long double xn, long double c)
{
  return xn - (function_x(xn) * (xn - c)) / (function_x(xn) - function_x(c));
}

int main()
{
  cout << setprecision(5) << endl;

  long double a = M_PI / 2;
  long double b = M_PI;
  long double c;
  long double xn;
  long double error = 0.001;

  set_c_xn(a, b, &c, &xn, error);

  do
  {
    xn = xn_(xn, c);
  } while (abs(function_x(xn)) >= error);

  cout << xn << endl;
}
