#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

typedef char LIST_TYPO[3][255];
typedef another_list

LIST_TYPO* get() {
  char a[3][255]{"Invanov", "Ivan", "Ivanovich"};
  LIST_TYPO list{"alpha", "beta", "gamma"};

  for (size_t i = 0; i < 3; i++) {
    for (size_t l = 0; l < 255; l++) {
      list[i][l] = a[i][l];
    }
  }

  return &list;
}

int main() {
  LIST_TYPO* m = get();
  string check = "alpha";

  for (size_t i = 0; i < 3; i++) {
    if ((*m)[i] == check) {
      cout << "True" << endl;
    } else {
      cout << (*m)[i] << ' ';
    }
  }

  return 0;
}
