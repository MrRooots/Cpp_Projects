#include <iostream>
#include <ctime>
using namespace std;

size_t *get_sum(size_t *first_array, size_t length_1, size_t *second_array, size_t length_2) {
  size_t length = length_1 + length_2;
  size_t *result_array = new size_t[length];

  for (size_t i = 0; i < length; i++) {
    if (i < length_1) {
      result_array[i] = first_array[i];
    } else {
      result_array[i] = second_array[i - length_1];
    }
  }

  return result_array;
}

int main() {
  srand(time(nullptr));

  size_t length_1;
  size_t length_2;
  cout << "Enter a length of arrays: "; cin >> length_1 >> length_2;

  size_t const length = length_1 + length_2;
  size_t first_array[length_1]{}, second_array[length_2]{};

  // Заполнение первого массива числами от 1 до 60
  cout << "First array: ";
  for (size_t i = 0; i < length_1; i++) {
    first_array[i] = rand()%61+10;
    cout << first_array[i] << ' ';
  }

  // Заполнение второго массива числами от 1 до 60
  cout << "\nSecond array: ";
  for (size_t i = 0; i < length_2; i++) {
    second_array[i] = rand()%61+10;
    cout << second_array[i] << ' ';
  }

  size_t *result = get_sum(first_array, length_1, second_array, length_2);

  cout << "\nResult array: ";
  for (size_t i = 0; i < length; i++) {
    cout << result[i] << ' ';
  }

  return 0;
}
