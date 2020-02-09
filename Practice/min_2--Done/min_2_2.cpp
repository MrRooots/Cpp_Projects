#include <iostream>
#include <sstream>
using namespace std;


// Перегруженная функция для поиска в переданном массиве
int find_in__function(double const array[], int LENGTH) {
  int counter = 0;  // Получение длины массива
  LENGTH -= 2;

  for (int i = 0; i < LENGTH; i++) {
    if (array[i] == 0 && array[i+1] == 0 && array[i+2] == 0) {
      counter += 1;
    }
  }

  // Возврат значения счетчика, если он не 0, иначе -1
  return counter != 0 ? counter : -1;
}


// Поисковая функция
int find_in__function(istream & stream) {
  int counter = 0;  // Счетчик
  double first, second, third;  // Считываемые элементы

  // Пока поток не пуст
  while (stream) {
    if (stream >> first) {
      for (second; stream >> second;) {
        for (third; stream >> third; first = second, second = third) {
          // cout << first << " " << second << " " << third << endl;
          if (first == 0 && second == 0 && third == 0) {
            counter += 1;
          }
        }
      }
    }
  }

  // Возврат значения счетчика, если он не 0, иначе -1
  return counter != 0 ? counter : -1;
}


// Построение потока
int stream_build_in(double const array[], int LENGTH) {
  stringstream stream;

  // Запись массива в поток
  for (int i = 0; i < LENGTH; ++i)
    stream << array[i] << ' ';

  return find_in__function(stream);  // Вызов поисковой функции от потока
}


// Тестировочная функция
string test_case_function(int (&searching_function)(double const*, int)) {
  int const LENGTH = 10;
  // double const array[LENGTH]{1, 2, 3, 4, 0, 0, 0, 0, 9, 10, 0, 0, 0, 14, 15, 16, 17, 18, 19, 20};

  double const t[] {0, 0, 0, 3, 4, 0, 0, 0, 0, 2, 0, 0, 0}; // Всего 4

  // Список тестов.
  size_t const NF = -1, // "not found"
    offset[] {  0,  0,  0,  0,  0,  0,  7,  7,  8,  8 },
    count[]  {  0,  5,  6,  8,  9, 13,  2,  6,  4,  5 },
    result[] { NF,  1,  1,  2,  3,  4, NF,  1, NF,  1 };

  for (int i = 0; i < LENGTH; ++i)
    if (searching_function(t + offset[i], count[i]) != result[i]) {
      return "Error in test cases!\n";
    }

  return "Succsesful!\n";

  // return searching_function(array, LENGTH) == 3;
}


int main() {
  cout << "First function: " << test_case_function(find_in__function);
  cout << "Second function: " << test_case_function(stream_build_in);

  return 0;
}
