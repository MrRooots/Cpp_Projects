// Блоки могут быть разной размерности!!!
#include <iostream>
using namespace std;

// Получение размерности (a на b) блока матрицы
size_t get_block_LENGTH(int *matrix, size_t start_pos, size_t end_pos) {
  size_t current_LENGTH = 0;  // Размерность блока матрицы

  // Проверка первого ряда на длину возможного квадрата
  for (size_t i = start_pos; i < end_pos; i++) {
    if (matrix[i] == 0) {
      return current_LENGTH;
    }
    current_LENGTH++;
  }

  return current_LENGTH;
}


// Для упакованного массива
bool is_block_diagonal(size_t LENGTH, int *matrix) {
  size_t current_LENGTH = get_block_LENGTH(matrix, 0, LENGTH);  // Размерность будущего блока
  size_t current_index = 0, i_counter = 1;  // Текущий индекс

  // Пройти первые current_LENGTH рядов в каждом брать по current_LENGTH символов
  // Разница между индексами в колонками 12, соответственно, если подряд, то first_in_new_row = last_index_in_row + 10
  while (current_index < LENGTH) {  // Пока не выйдем за границы массива
    // Проход по всем диагональным блокам матрицы

    // На каждом окончании блока проверить длину следующего блока
    if (i_counter % (current_LENGTH+1) != 0) {
      // Прыжок должен осуществлятся в зависимости от длины блока
      if (matrix[current_index] != 0 && matrix[current_index + 1] != 0 && matrix[current_index + 2] != 0) {
        current_index += 12;  // Прыжок на следующий ряд
        i_counter++;
      } else {
        return false;
      }
    } else {
      if (current_index + current_LENGTH < LENGTH) {
        current_index += current_LENGTH;
        i_counter = 1;
      }
    }
  }

  return true;
}

// Тест функция
void test_case_function(bool (&is_block_diagonal)(size_t, int*)) {
  size_t const LENGTH = 12;

  // Текущий тест
  int packed_matrix_0[LENGTH*LENGTH]{7,7,7, 0,0,0, 0,0,0, 0,0,0,  // 0  1  2
                                     7,7,7, 0,0,0, 0,0,0, 0,0,0,  // 12 13 14
                                     7,7,7, 0,0,0, 0,0,0, 0,0,0,  // 24 25 26

                                     0,0,0, 9,9,9, 3,3,3, 0,0,0,  // 39 40 41
                                     0,0,0, 9,9,9, 3,3,3, 0,0,0,  // 51 52 53
                                     0,0,0, 9,9,9, 3,3,3, 0,0,0,  // 63 64 65  Делать через снос длины верхнего блока на нижний для получения его лины

                                     0,0,0, 3,3,3, 3,3,3, 0,0,0,
                                     0,0,0, 3,3,3, 3,3,3, 0,0,0,
                                     0,0,0, 3,3,3, 3,3,3, 0,0,0,

                                     0,0,0, 0,0,0, 0,0,0, 8,8,8,
                                     0,0,0, 0,0,0, 0,0,0, 8,8,8,
                                     0,0,0, 0,0,0, 0,0,0, 8,8,8} ;// 141 142 143

  int packed_matrix_1[LENGTH*LENGTH]{7,7,7, 7,7,7, 0,0,0, 0,0,0,  // 0  1  2
                                     7,7,7, 7,7,7, 0,0,0, 0,0,0,  // 12 13 14
                                     7,7,7, 7,7,7, 0,0,0, 0,0,0,  // 24 25 26

                                     7,7,7, 9,9,9, 0,0,0, 0,0,0,  // 39 40 41
                                     7,7,7, 9,9,9, 0,0,0, 0,0,0,  // 51 52 53
                                     7,7,7, 9,9,9, 0,0,0, 0,0,0,  // 63 64 65

                                     0,0,0, 0,0,0, 3,3,3, 7,7,7,
                                     0,0,0, 0,0,0, 3,3,3, 7,7,7,
                                     0,0,0, 0,0,0, 3,3,3, 7,7,7,

                                     0,0,0, 0,0,0, 7,7,7, 8,8,8,
                                     0,0,0, 0,0,0, 7,7,7, 8,8,8,
                                     0,0,0, 0,0,0, 7,7,7, 8,8,8};// 141 142 143
 size_t length_1 = 27 * 27;
 // В этом тесте ошибка в строке 4 колонке 5)
 int packed_matrix_2[length_1]    { 7,7,7, 7,7,7, 9,9,9, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
                                    7,7,7, 7,7,7, 9,9,9, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
                                    7,7,7, 7,7,7, 9,9,9, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,

                                    7,7,7, 9,9,9, 9,9,9, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
                                    7,7,7, 9,9,9, 9,9,9, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
                                    7,7,7, 9,9,9, 9,9,9, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,

                                    3,3,3, 3,3,3, 7,7,7, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
                                    3,3,3, 3,3,3, 7,7,7, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
                                    3,3,3, 3,3,3, 7,7,7, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,

                                    0,0,0, 0,0,0, 0,0,0, 7,7,7, 0,0,0, 9,9,9, 0,0,0, 0,0,0, 0,0,0,
                                    0,0,0, 0,0,0, 0,0,0, 7,7,7, 0,0,0, 9,9,9, 0,0,0, 0,0,0, 0,0,0,
                                    0,0,0, 0,0,0, 0,0,0, 7,7,7, 0,0,0, 9,9,9, 0,0,0, 0,0,0, 0,0,0,

                                    0,0,0, 0,0,0, 0,0,0, 7,7,7, 7,7,7, 9,9,9, 0,0,0, 0,0,0, 0,0,0,
                                    0,0,0, 0,0,0, 0,0,0, 7,7,7, 7,7,7, 9,9,9, 0,0,0, 0,0,0, 0,0,0,
                                    0,0,0, 0,0,0, 0,0,0, 7,7,7, 7,7,7, 9,9,9, 0,0,0, 0,0,0, 0,0,0,

                                    0,0,0, 0,0,0, 0,0,0, 7,7,7, 7,7,7, 9,9,9, 0,0,0, 0,0,0, 0,0,0,
                                    0,0,0, 0,0,0, 0,0,0, 7,7,7, 7,7,7, 9,9,9, 0,0,0, 0,0,0, 0,0,0,
                                    0,0,0, 0,0,0, 0,0,0, 7,7,7, 7,7,7, 9,9,9, 0,0,0, 0,0,0, 0,0,0,

                                    0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 3,3,3, 3,3,3, 7,7,7,
                                    0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 3,3,3, 3,3,3, 7,7,7,
                                    0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 3,3,3, 3,3,3, 7,7,7,

                                    0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 3,3,3, 3,3,3, 7,7,7,
                                    0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 3,3,3, 3,3,3, 7,7,7,
                                    0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 3,3,3, 3,3,3, 7,7,7,

                                    0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 3,3,3, 3,3,3, 7,7,7,
                                    0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 3,3,3, 3,3,3, 7,7,7,
                                    0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 3,3,3, 3,3,3, 7,7,7};

  is_block_diagonal(LENGTH*LENGTH, packed_matrix_0) ? cout << "Succesful!\n" : cout << "Fail\n";
  is_block_diagonal(LENGTH*LENGTH, packed_matrix_1) ? cout << "Succesful!\n" : cout << "Fail\n";
  is_block_diagonal(length_1, packed_matrix_2)      ? cout << "Succesful!\n" : cout << "Fail\n";
}


int main() {
  // Определить, является ли матрица блочно-диагональной.
  // Блочно-диагональной называется матрица, составленная из квадратных блоков нечётного размера, расставленных по главной диагонали.
  // Элементы вне блоков равны нулю.
  test_case_function(is_block_diagonal);

  return 0;
}
