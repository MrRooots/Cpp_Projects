#include <iostream>
using namespace std;

template<typename T>
size_t get_lengt(T array[]) {
  size_t length = 0;
  while (array[length++]) {}
  return length;
}

template<typename T>
T find_max(T array[]) {
  T max = array[0];
  size_t length = get_lengt(array);
  for (size_t i = 0; i < length; i++) {
    if (array[i] >= max) {
      max = array[i];
    }
  }
  return max;
}

int main() {
  double array[]{1.,2.,3.,4.,5.,6.};
  cout << find_max(array);
  return 0;
}
