// Вывести значение функции f(x) = e^Y - 1000^-Y в точках n/16 - 1, n = 0, 1,…, 32.
// Значение Y = ⌊x⌋ - x должно вычисляться однократно для каждого n.

#include <iostream>
#include <cmath>
using namespace std;

float function(float x) {
  float y = floor(x) - x;

  return exp(y) - pow(1000, -y);
};

int main() {
  double current_;

  for (float i = 0; i < 33; i++) {
    current_ = i/16 - 1;
    cout << "Значение функции в точке " << current_ << " равно: " << function(current_) << endl;
  };

  return 0;
}
