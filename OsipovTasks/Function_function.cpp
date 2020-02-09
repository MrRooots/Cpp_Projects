#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Тут задаются функции
double first_function (double x) {
  return x * x + 4*x * 1;
}

double second_function (double x) {
  return sin(x)/cos(x) * (sin(x) * x* x * 4) + 11;
}

double third_function (double x) {
  return log(x);
}

string string_function(string line) {
  return line;
} 


// Печать значений переданной функции
void printer(double (&current_function)(double), double left, double right, double interval) {
  cout << "Function:\t" << setw(5) << "Result:" << endl;  // Заголовок

  for (int i = left; i < right; i+=interval) {
    cout << "f(" << i << ")\t" << setw(9) << '|' << current_function(i) << endl;  // Сами значения f(x)
  }
}


void printer(string (&current_function)(string), string line, double left, double right, double interval) {
  cout << "Function:\t" << setw(5) << "Result:" << endl;  // Заголовок

  for (double i = left; i < right+1; i+=interval) {
    cout << "f(" << i << ")\t" << setw(9) << '|' << current_function(line) << endl;  // Сами значения f(x)
  }
}


int main() {
  printer(first_function, -5, 5, 1);
  cout << endl;

  printer(second_function, -5, 5, 1);
  cout << endl;

  printer(third_function, -5, 5, 1);
  cout << endl;

  printer(string_function, "string function", -5, 5, 2.5);
  cout << endl;

  return 0;
}
