#include <iostream>
using namespace std;

// Вывести минимум положительных чисел (или нуль) и вернуть произведение неотрицательных чисел.
int array_checker(int array[], int length) {
  int min_element = 0;  // Минимальный элемент
  long int product=1;  // Произведение

  // Поиск первого неотрицательного элемента
  for (int i = 0; i < length; i++) {
    if (array[i] > 0) {
      min_element = array[i];
      break;
    }
  }

  // Оценка значений элеметнов массива
  for (int i = 0; i < length; i++) {
    if (array[i] >= 0) {
      product *= array[i];  // Произведение неотрицательных чисел
    }
    if (array[i] > 0 && array[i] < min_element) {
      min_element = array[i];  // Минимум положительных элеметнов
    }
  }

  cout << "Minimal element: " << min_element << endl;  // Вывод минимума
  return product;  // Возврат произведения
}

int main() {
  int const length = 18;
  int lst[length] = {-1, -2, -3, -4, -5, -6, -7, -8, -1, -10, -11, -12, -13, -14, -15, -16, -17, -18};

  cout << "Product: " << array_checker(lst, length);

  return 0;
}
