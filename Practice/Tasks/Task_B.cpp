#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <typeinfo>
using namespace std;

vector<vector<size_t>> main_matrix;

// Получит произвольный контейнер  --> переделает в vector<T>
template <template <typename, typename> class Input, typename T, typename A>  
void append_to_matrix(const Input<T, A>& array) {
  vector<T> result;
  
  for (auto x : array) {
    result.push_back(x);
  }
  main_matrix.push_back(result);
}

// Получит container<container<T>> --> будет разбивать и по одному отправлять на переделку в vector<T>
template <template <typename, typename> class Input, typename T, typename A>  
void split_containers(const Input<T, A>& array) {
  for (auto x : array) {
    append_to_matrix(x);  // Добавим все контейнеры в главную матрицу
  }
}

template <typename T>
bool is_diagonal(vector<vector<T>> matrix) {
  size_t dimension = matrix.size();  // Размерность матрицы
  size_t zero_count = 0;

  // Проверка главной диагонали
  for (size_t i = 0; i < dimension; i++) {
    if (matrix[i][i] == 0) {
      zero_count++;
    }
  }
  if (zero_count == dimension) {
    return false;
  } else {
    zero_count = 0;
    dimension--;  // Уменьшим размерность для дальнейших проверок
  }
  // Проверка двух прилегающих диагоналей
  for (size_t i = 0; i < dimension; i++) {
    if (matrix[i][i+1] == 0) {
      zero_count++;
    }
    if (matrix[i+1][i] == 0) {
      zero_count++;
    }
  }
  if (zero_count == dimension*2) {
    return false;
  } else {
    zero_count = 0;
    dimension--;
  }
  // Проверка двух прилегающих к прилегающим диагоналям диагоналей
  for (size_t i = 0; i < dimension; i++) {
    if (matrix[i+2][i] == 0) {
      zero_count++;
    }
    if (matrix[i][i+2] == 0) {
      zero_count++;
    }
  }
  if (zero_count == dimension) {
    return false;
  } else {
    return true;
  }
}

void test_function() {
  // То что передадим на переделку в vector<T>
  const deque<deque<size_t>> to_vector = {
    {2, 1, 1, 0, 0, 0},
    {1, 2, 1, 0, 0, 0},
    {2, 3, 4, 5, 0, 0},
    {0, 4, 2, 1, 1, 0},
    {0, 0, 1, 1, 2, 2},
    {0, 0, 0, 1, 1, 2}
  };
  
  split_containers(to_vector);

  if (is_diagonal(main_matrix)) {
    cout << "The matrix is five-diagonal!" << endl;
  } else {
    cout << "The matrix is NOT five-diagonal!" << endl;
  }
}

int main() {
  test_function();
  return 0;
}