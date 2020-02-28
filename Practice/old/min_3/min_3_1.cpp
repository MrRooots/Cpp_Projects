#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

// Список констант
double const // Вспомогательные числовые константы:
  HALF_PI   = 1.5707963267948966,   // половина пи,
  PI        = 3.1415926535897932,   // число пи,
  DOUBLE_PI = 6.2831853071795865,   // два пи,
  EPSILON = 1e-10;                // граница между "нулём" и "ненулём".

// Если cos(expression) принадлежит EPSILON окрестности 0
bool does_expression_exist(double x, double c=1) {
  double c_in_pow = c*c*c, x_in_pow = x*x*x*x;
  double expression = c_in_pow * x_in_pow;  // Проверить на попадание в pi/2+pi*k, где к - целые

  if (cos(expression) < EPSILON && cos(expression) > -EPSILON) {
    return false;
  }
  return true;
}

// Для корня не должно найтись такого k, что c_in_pow*x_in_pow == pi/2+pi*k
double solve_it(double x, double a, double b, double c) {
  double c_in_pow = c*c*c;
  double x_in_pow = x*x*x*x;
  cout << "Bool: " << does_expression_exist(x_in_pow, c_in_pow) << endl;

  if (does_expression_exist(x_in_pow, c_in_pow)) {
    return sin(a*PI*cos(b*b*(sin(c_in_pow*x_in_pow)/cos(c_in_pow*x_in_pow))));
  } else {
    cout << "Doesn't exist!";
    return 0;
  }
}

// Точка входа
int main() {
  srand(time(nullptr));

  double argument_list[20]{24, 92, 0.43, 65, 6.3, 5.7, 21, 6.7, 61.4, 34, 31.6, 1, 7.8, 41, 86, 7.1, 98, 8.0, .60, 94};
  double a = argument_list[rand()%20], b = argument_list[rand()%20], c = argument_list[rand()%20];

  cout << "A: " << a << " B: " << b << " C: " << c << endl;
  cout << solve_it(1, a, b, pow(HALF_PI, (double)1/3));  // Решение для известных значений

  // does_expression_exist(1, 2);

  return 0;
}
