#include <iostream>
#include <vector>
#include <typeinfo>
#include <list>
#include <deque>
using namespace std;

// Вопрос!!!
// T - имя типа vetor<T> а А - какой-то allocator из определения, например vector: {template<class T, class Allocator = allocator<T>>}
// По итогу получаем, что Input <типа T, с аллокатором A>, который говорит сколько памяти выдать под контейнер или под каждую перменную типа Т? 
// Или что он делает?
template <template <typename, typename> class Input, typename T, typename A>  
vector<T> create_vector(Input<T, A>& input) {  
  // Создадим вектор из принятого контейнера (vector_array)
  vector<T> vector_array, result;
  size_t length = input.size();
  for (auto x : input) {
    vector_array.push_back(x);
  }

  // Построим массив убывания/возрастания, не допуская повторений (result)
  for (size_t i = 0; i < length - 1; i++) {
    if (result.size() > 0) {
      if (vector_array[i] < vector_array[i + 1] && result[result.size() - 1] != 1) {
        result.push_back(1);
      } else if (vector_array[i] > vector_array[i + 1] && result[result.size() - 1] != -1) {
        result.push_back(-1);
      } else if (vector_array[i] == vector_array[i + 1] && result[result.size() - 1] != 0) {
        result.push_back(0);
      }
    } else {
      if (vector_array[i] < vector_array[i + 1]) {
        result.push_back(1);
      }
      if (vector_array[i] > vector_array[i + 1]) {
        result.push_back(-1);
      }
      if (vector_array[i] == vector_array[i + 1]) {
        result.push_back(0);
      }
    }
  }
  
  return result;
}

// Сравнение массивов
bool is_equal(const vector<int> array) {
  const size_t length = array.size();
  const vector<int> assert_array {1, -1, 0, 1, 0};

  for (size_t i = 0; i < length; i++) {
    if (array[i] != assert_array[i]) {
      return false;
    }
  }
  return true;
}

void tast_test_function() {
  // { 1, 3, 5, 3, 1, 0, 0, 2, 4, 5, 5, 5 } ---> { 1, -1, 0, 1, 0 }
  deque<int>  deque_array  {1, 3, 5, 3, 1, 0, 0, 2, 4, 5, 5, 5};
  list<int>   list_array   {1, 3, 5, 3, 1, 0, 0, 2, 4, 5, 5, 5};
  vector<int> vector_array {1, 2, 3, 4, 5, 0, 0, 4, 0, 6, 7, 2};

  if (is_equal(create_vector(deque_array))) {
    cout << "First Passed!" << endl;
  } else {
    cout << "First Failed!" << endl;
  }
  if (is_equal(create_vector(list_array))) {
    cout << "Second Passed!" << endl;
  } else {
    cout << "Second Failed!" << endl;
  }
  if (is_equal(create_vector(vector_array))) {
    cout << "Third Passed!" << endl;
  } else {
    cout << "Third Failed!" << endl;
  }
    
}

int main() {
  tast_test_function();
}
