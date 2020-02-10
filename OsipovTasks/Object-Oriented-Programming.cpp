#include <iostream>
using namespace std;

bool isInsideOnce(size_t *array, size_t length, size_t element) {
  size_t count = 0;  // Кол-во встречаемости

  for (size_t i = 0; i < length; i++) {
    if (array[i] == element) {
      count++;
    }
  }

  return true ? count == 1 : false;
}

bool isPartition(size_t *array, size_t length) {
  for (size_t i = 0; i < length; i++) {
    if (!isInsideOnce(array, length, array[i])) {
      return false;
    }
  }

  return true;
}

int main() {
  size_t length;
  cout << "Enter a count of elements: "; cin >> length;

  size_t *array = new size_t[length];

  for (size_t i = 0; i < length; i++) {
    array[i] = i+1;
  }

  for (size_t i = 0; i < length; i++) {
    cout << array[i] << ' ';
  }

  cout << endl;

  if (isPartition(array, length)) {
    cout << "True";
  } else {
    cout << "False";
  }

  return 0;
}
