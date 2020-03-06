#include <iostream>
#include <vector>
#include <deque>
#include <typeinfo>
#include <cstring>
using namespace std;

template <typename T>
bool get_diagonal(vector<vector<T>> matrix) {
  size_t dimension = matrix.size();  // Размерность матрицы
  size_t zero_count = 0;

  // Проверка главной диагонали
  cout << "Main diagonal: ";
  for (size_t i = 0; i < dimension; i++) {
    if (matrix[i][i] == 0) {
      zero_count++;
    }
    cout << matrix[i][i] << ' ';
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

template<template<typename, typename> class Input, typename T, typename A>
vector<T> beta(Input<T, A>& array) {
  vector<T> result;
  for (auto x : array) {
    result.push_back(x);
  }
  return result;
}

template<template<typename, typename> class Input, typename T, typename A>
void alpha(Input<T, A>& array) {  // -> T - deque<size_t>
  
}

// Указатели и строки
int main() {
  deque<deque<size_t>> matrix = {
    {2, 1, 1, 0, 0, 0},
    {1, 2, 1, 0, 0, 0},
    {2, 3, 4, 5, 0, 0},
    {0, 4, 2, 1, 1, 0},
    {0, 0, 1, 1, 2, 2},
    {0, 0, 0, 1, 1, 2}
  };

  alpha(matrix);
  vector<vector<size_t>> ar;
  vector<size_t> a {1,2,3};
  ar.push_back(a);
  return 0;
}