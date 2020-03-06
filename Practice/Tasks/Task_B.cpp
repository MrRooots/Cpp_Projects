#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <typeinfo>
using namespace std;

// Получит произвольный контейнер  --> переделает в vector<T>
template <template <typename, typename> class Input, typename T, typename A>  
vector<T> get_container_inside(const Input<T, A>& array) {
  vector<T> result;
  
  for (auto x : array) {
    result.push_back(x);
  }
  return result;  // Вектор шаблонных элементов
}

// Получит container<container<T>> --> будет разбивать и по одному отправлять на переделку в vector<T>
template <template <typename, typename> class Input, typename T, typename A>  
void re_build(const Input<T, A>& array) {  
  for (auto x : array) {
    
  }
}

// template <typename T>
// bool is_diagonal(vector<vector<T>> matrix) {
//   size_t dimension = matrix.size();  // Размерность матрицы
//   size_t zero_count = 0;

//   // Проверка главной диагонали
//   cout << "Main diagonal: ";
//   for (size_t i = 0; i < dimension; i++) {
//     if (matrix[i][i] == 0) {
//       zero_count++;
//     }
//     cout << matrix[i][i] << ' ';
//   }
//   if (zero_count == dimension) {
//     return false;
//   } else {
//     zero_count = 0;
//     dimension--;  // Уменьшим размерность для дальнейших проверок
//   }
//   // Проверка двух прилегающих диагоналей
//   for (size_t i = 0; i < dimension; i++) {
//     if (matrix[i][i+1] == 0) {
//       zero_count++;
//     }
//     if (matrix[i+1][i] == 0) {
//       zero_count++;
//     }
//   }
//   if (zero_count == dimension*2) {
//     return false;
//   } else {
//     zero_count = 0;
//     dimension--;
//   }
//   // Проверка двух прилегающих к прилегающим диагоналям диагоналей
//   for (size_t i = 0; i < dimension; i++) {
//     if (matrix[i+2][i] == 0) {
//       zero_count++;
//     }
//     if (matrix[i][i+2] == 0) {
//       zero_count++;
//     }
//   }
//   if (zero_count == dimension) {
//     return false;
//   } else {
//     return true;
//   }
// }

int main() {
  // То что передадим на переделку в vector<T>
  const deque<deque<size_t>> to_vector = {
    {2, 1, 1, 0, 0, 0},
    {1, 2, 1, 0, 0, 0},
    {2, 3, 4, 5, 0, 0},
    {0, 4, 2, 1, 1, 0},
    {0, 0, 1, 1, 2, 2},
    {0, 0, 0, 1, 1, 2}
  };
  
  re_build(to_vector);

  // cout << "Converted matrix is: ";
  // for (size_t i = 0; i < matrix.size(); i++) {
  //   for (size_t l = 0; l < matrix[i].size(); l++) {
  //     cout << matrix[i][l] << ' ';
  //   }
  // }
  // cout << endl;

  // if (is_diagonal(matrix)) {
  //   cout << "The matrix is five-diagonal" << endl;
  // } else {
  //   cout << "The matrix is not five-diagonal" << endl;
  // }

  return 0;
}