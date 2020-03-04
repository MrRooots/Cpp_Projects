#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cmath>
using namespace std;

vector<size_t> matrix;  // Упакованная матрица

// Получит vector<T> добавит к общему
template<typename T>
void create_vector(vector<T> array_to_append) {  
  for (auto x : array_to_append) {
    matrix.push_back(x);
  }  
}

// Получит произвольный контейнер  --> переделает в vector<T>
template <template <typename, typename> class Input, typename T, typename A>  
vector<T> get_container_inside(const Input<T, A>& array) {
  vector<T> result;
  
  for (auto x : array) {
    result.push_back(x);
  }

  return result;
}

// Получит container<container<T>> --> будет разбивать и по одному отправлять на переделку в vector<T>
template <template <typename, typename> class Input, typename T, typename A>  
void get_container(const Input<T, A>& array) {
  // size_t length = array.size();

  for (auto x : array) {
    create_vector(get_container_inside(x));
  }
}

template<typename T>
bool is_diagonal(vector<T> matrix) {
  // Проверить, стоят ли НЕ нули вне главной и 4 прилегающих к ней диагоналях
  size_t col_row_length = sqrt(matrix.size());  // Размерность матрицы
  
  // Если размерность меньше трех --> не может быть пятидиагональной
  if (col_row_length < 3) {
    return false;
  }

  // Перебор
  

  return false;
}

int main() {
  // То что передадим на переделку в vector<T>
  deque<deque<size_t>> to_vector = {
    {2, 1, 1, 0, 0, 0},
    {1, 2, 1, 0, 0, 0},
    {2, 3, 4, 5, 0, 0},
    {0, 4, 2, 1, 1, 0},
    {0, 0, 1, 1, 2, 2},
    {0, 0, 0, 1, 1, 2}
  };
  
  get_container(to_vector);

  cout << "Converted matrix is: ";
  for (size_t i = 0; i < matrix.size(); i++) {
    cout << matrix[i] << ' ';
  }
  cout << endl;

  if (is_diagonal(matrix)) {
    cout << "The matrix is five-diagonal" << endl;
  } else {
    cout << "The matrix is not five-diagonal" << endl;
  }

  return 0;
}