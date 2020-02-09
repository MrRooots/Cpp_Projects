#include <math.h>   // Описания математических функций
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

// Прототип функции приведения матрицы к ступенчатому виду.
int gauss_method(
  int rows,          // Число строк матрицы
  int columns,          // Число столбцов матрицы
  double *a,      // Адрес массива элементов матрицы
  double eps      // Точность вычислений
);

int main() {
  srand(time(nullptr));
  int rows, columns, rank;
  double *a;
  double eps, det;
  cout << "Enter a size of matrix(rows, columns): "; cin >> rows >> columns;

  // Выделение памяти
  a = (double *) malloc(rows * columns * sizeof(double));

  cout << "Before Gauss:" << endl;
  // Заполнение
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < columns; ++j) {
      a[i*columns + j] = rand()%20+1;
      cout << a[i*columns + j] << '\t';
    }
    cout << endl;
  }

  eps = .1;  // Погрешность для будущих вычислений

  // Вызываем метод Гаусса
  gauss_method(rows, columns, a, eps);

  // Вывод результата матрицы
  cout << "Result: " << endl;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < columns; ++j) {
      cout << setw(10) << a[i*columns + j];
    }
    cout << endl;
  }

  free(a); // Освобождаем память
  return 0;
}

int gauss_method(int rows, int columns, double *a, double eps) {
  size_t i, j, k, l;
  double temp_max;
  i = 0; j = 0;

  while (i < rows && j < columns) {
    temp_max = .0;
    for (k = i; k < rows; ++k) {
      if (fabs(a[k*columns + j]) > temp_max) {
        l = k;  // Запомним номер строки
        temp_max = fabs(a[k*columns + j]);  // и макс. эл-т
      }
    }
    if (temp_max <= eps) {
      // Все элементы j-го столбца по абсолютной величине не превосходят eps -> обнулим столбец, начиная с i-й строки
      for (k = i; k < rows; ++k) {
        a[k*columns + j] = 0.0;
      }
      ++j;
      continue;  // Переходим к следующей итерации
    }

    if (l != i) {
      // Меняем местами i-ю и l-ю строки
      for (k = j; k < columns; ++k) {
        temp_max = a[i*columns + k];
        a[i*columns + k] = a[l*columns + k];
        a[l*columns + k] = (-temp_max);  // Меняем знак строки
      }
    }

    // Обнуляем j-й столбец, начиная со строки i+1, применяя элем. преобразования второго рода
    for (k = i+1; k < rows; ++k) {
      temp_max = (-a[k*columns + j] / a[i*columns + j]);
      // К k-й строке прибавляем i-ю, умноженную на r
      a[k*columns + j] = 0.0;
      for (l = j+1; l < columns; ++l) {
        a[k*columns + l] += temp_max * a[i*columns + l];
      }
    } 

    ++i; ++j;   // Переходим к следующему минору
  }

  return i; // Возвращаем число ненулевых строк
}
