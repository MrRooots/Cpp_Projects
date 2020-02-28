// Блоки могут быть разной размерности!!!
#include <iostream>
#include <cmath>
using namespace std;

// Получение длины каждого из блока (n*n)
size_t get_block_length(size_t *matrix, size_t matrix_length, size_t row_number=0, size_t distance_from_previous_block=0) {
  size_t length = 0;

  if (row_number == 0) {
    for (size_t i = 0; i < matrix_length; i++) {
      if (matrix[i] == 0) {
        return i;
      }
    }
  } else {
    size_t start_pos = matrix_length * row_number + distance_from_previous_block;

    for (size_t i = 0; i < matrix_length; i++) {
      if (matrix[start_pos + i] == 0) {
        return length;
      }
      length++;
    }
  }
}

// Получение длины будущего массива
size_t get_array_size(size_t *matrix, size_t LENGTH) {
  size_t row_length = sqrt(LENGTH);  // Количество рядов в квадратной матрице
  size_t current_block_length = get_block_length(matrix, row_length);  // Размерность первого блока
  size_t index = 0, distance_from_previous_block = 0;  // Подсчет отставания блока

  for (size_t i = 0; i < row_length; i++) {
    if (i == distance_from_previous_block) {
      current_block_length = get_block_length(matrix, row_length, i, distance_from_previous_block);

      for (size_t l = 0; l < current_block_length; l++) {
        for (size_t k = 0; k < current_block_length; k++) {
          index++;
        }
      }

      distance_from_previous_block += current_block_length;
    }
  }

  return index;
}

// Проверка на нахождение символа в массиве
bool is_inside(int element, size_t *array, size_t array_length) {
  for (size_t i = 0; i < array_length; i++) {
    if (array[i] == element) {
      return true;
    }
  }

  return false;
}


bool is_block_diagonal(size_t LENGTH, size_t *matrix) {
  size_t row_length = sqrt(LENGTH);  // Количество рядов в квадратной матрице
  size_t current_block_length = get_block_length(matrix, row_length);  // Размерность первого блока
  size_t distance_from_previous_block = 0;  // Подсчет отставания блока
  size_t array_length = get_array_size(matrix, LENGTH);
  size_t temp_counter = 0;

  size_t array_of_index[array_length]{};  // Массив индексов для проверки

  for (size_t i = 0; i < row_length; i++) {
    // Если итерация по ряда дошла до конца текущего блока - получаем длину следующего
    if (i == distance_from_previous_block) {
      current_block_length = get_block_length(matrix, row_length, i, distance_from_previous_block);

      if (current_block_length % 2 == 0) {
        return false;
      }

      // Постепенное заполнение массива
      for (size_t l = 0; l < current_block_length; l++) {
        for (size_t k = 0; k < current_block_length; k++) {
          array_of_index[temp_counter++] = (l+distance_from_previous_block) * row_length + distance_from_previous_block + k;
        }
      }

      distance_from_previous_block += current_block_length;
    }

  }

  for (size_t i = 0; i < LENGTH; i++) {
    if (!is_inside(i, array_of_index, array_length) && matrix[i] != 0) {
      return false;
    }
  }

  return true;
}


// Тест функция
void test_case_function() {
  size_t const LENGTH = 16;

  // Текущий тест
  size_t matrix[LENGTH*LENGTH] {
              7,7,7, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,  //  0       0
              7,5,7, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,  //  1       11
              1,1,1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,  //  2       22

              0,0,0, 9,9,9,9,9, 0,0,0,0,0, 0,0,0,  //  3       36
              0,0,0, 9,1,1,1,9, 0,0,0,0,0, 0,0,0,  //  4       47
              0,0,0, 9,1,5,1,9, 0,0,0,0,0, 0,0,0,  //  5       58
              0,0,0, 9,1,1,1,9, 0,0,0,0,0, 0,0,0,  //  6       69
              0,0,0, 9,9,9,9,9, 0,0,0,0,0, 0,0,0,  //  7       80

              0,0,0, 0,0,0,0,0, 9,9,9,9,9, 0,0,0,
              0,0,0, 0,0,0,0,0, 9,1,1,1,9, 0,0,0,
              0,0,0, 0,0,0,0,0, 9,1,5,1,9, 0,0,0,
              0,0,0, 0,0,0,0,0, 9,1,1,1,9, 0,0,0,
              0,0,0, 0,0,0,0,0, 9,9,9,9,9, 0,0,0,

              0,0,0, 0,0,0,0,0, 0,0,0,0,0, 8,8,8,  //  8       80 + 11 + distance_from_previous_block = 96
              0,0,0, 0,0,0,0,0, 0,0,0,0,0, 8,5,8,  //  9       107
              0,0,0, 0,0,0,0,0, 0,0,0,0,0, 8,8,8   //  10      118
            };

  is_block_diagonal(LENGTH*LENGTH, matrix) ? cout << "Succesful!\n" : cout << "Failed!\n";
}


int main() {
  // Определить, является ли матрица блочно-диагональной.
  // Блочно-диагональной называется матрица, составленная из квадратных блоков нечётного размера, расставленных по главной диагонали.
  // Элементы вне блоков равны нулю.
  test_case_function();

  return 0;
}
