#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;


// Вариант 1. Массив указателей на строки.
bool is_matrix_triangle(double const* const* matrix, int rows, int cols) {
  // Проверка на верхнетреугольность матрицы
  if (cols != rows) {
    return false;
  }

  for (int i = 1; i < rows; i++) {
    for (int j = 0; j < i; j++) {
      if (matrix[i][j] != 0) {
        return false;
      }
    }
  }

  return true;
}


// Вариант 2. Упакованный массив.
bool is_matrix_triangle(double const matrix[], int rows, int cols) {
  int current_index = 0, counter = 0;

  // Проверка на верхнетреугольность матрицы
  if (cols != rows) {
    return false;
  }

  for (size_t i = 0; i < rows; i++) {
    for (size_t l = 0; l < current_index; l++) {
      if (matrix[counter+l] != 0) {
        return false;
      }
    }
    counter += cols;  // Накапливающий счетчик
    current_index += 1;  // Сдвиг кол-ва проверяющихся индексов вплоть до диагонального элемента
  }

  return true;
}

// Обёртка для теста упакованного массива как массива указателей.
bool is_01matrix_packed_adapter(double const matrix[], int rows, int cols) {
  // Создадим временный массив для хранения указателей на строки.
  auto temp_array  = new double const*[rows];

  for (int i = 0; i < rows; ++i, matrix += cols) {
    temp_array[i] = matrix;
  }

  // Вызовем функцию is_01matrix.
  bool result = is_matrix_triangle(temp_array, rows, cols);

  delete[] temp_array;  // Удалим массив.

  return result;  // Вернём полученный результат.
}


void test_case_function(bool (&some_function)(double const matrix[], int rows, int cols)) {
  srand(time(nullptr));

  // Генератор рандомных матриц
  for (size_t i = 0; i < 3; i++) {
    int length = rand()%10+4;  // Генерация произвольной длины строки матрицы
    double matrix_1[length*length];

    for (size_t i = 0; i < length; i++) {
      for (size_t l = 0; l < length; l++) {
        // Условие того, что под диагональю матрицы будет стоять ноль --> Вероятность 97%
        if (l < i && rand()%100 < 97) {
          matrix_1[i*length+l] = 0;
        } else {
          matrix_1[i*length+l] = rand()%100;  // На верхней диагонали генерируются рандомные числа
        }
      }
    }

    // Вывод матрицы для проверки верности программы
    for (size_t i = 0; i < length; i++) {
      for (size_t l = 0; l < length; l++) {
        cout << setw(3) << matrix_1[i*length+l];
      }
      cout << '\n';
    }

    // Вызов определенной функции от сгенерированной матрицы на последующую проверку
    if (some_function(matrix_1, length, length)) {
      cout << "Result: Succsessful!\n\n";
    } else {
      cout << "Result: Error!\n\n";
    }
  }
}


int main() {
  cout << "---------------------------------------First test case (Matrix is packed array)----------------------------------------" << endl << endl;
  test_case_function(is_matrix_triangle);
  cout << "---------------------------------------Second test case (Matrix is array of pointers)----------------------------------" << endl << endl;
  test_case_function(is_01matrix_packed_adapter);
  return 0;
}
