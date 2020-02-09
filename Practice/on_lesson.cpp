#include <iostream>
using namespace std;

size_t some_func() {
  return 190;
}

int main() {
  long double a = 10000000000;  

  for (long double i = 0; i < a; i++) {
    some_func();
  }

}
