// Доделано\отлажено
#include <iostream>
#include <ctime>
using namespace std;

// Сортировка тройки пузырьком
int sort_triplet(int array[]) {
  if (array[0] > array[1]){
    int temp = array[1];
    array[1] = array[0];
    array[0] = temp;
  }
  if (array[1] > array[2]){
    int temp = array[1];
    array[1] = array[2];
    array[2] = temp;
  }
  if (array[0] > array[1]){
    int temp = array[1];
    array[1] = array[0];
    array[0] = temp;
  }

  return array[1];  // Возврат серединного элемента
}

// Дробление массива
double array_splitter(size_t const LENGTH, int array[]) {
  size_t index = 0, triplet_count = LENGTH / 3;
  double sum_of_middle = .0;  // Сумма средних элеметов троек
  int to_sort[3]{};  // Постоянно перезаполняемый массив троек

  size_t count_last_elements = LENGTH - triplet_count * 3;  // Кол-во лишних элементов
  double sum_last_elements = 0;

  // u - верхний пробег, l - нижний (внутренний) пробег
  for (size_t u = 0; u < triplet_count; u++) {
    for (size_t l = 0; l < 3; l++) {
      to_sort[l] = array[index++];
    }
    sum_of_middle += sort_triplet(to_sort);
  }
  if (count_last_elements == 1) {
    sum_last_elements += array[LENGTH - 1];
  } else if (count_last_elements == 2) {
      sum_last_elements += (array[LENGTH - 1] + array[LENGTH - 2]);
      sum_last_elements = sum_last_elements / 2;
  }

  return count_last_elements > 0 ? (sum_of_middle + sum_last_elements) / (triplet_count + 1) : (sum_of_middle + sum_last_elements) / (triplet_count);

}

void test_case_function(double (&array_splitter)(size_t const LENGTH, int array[])) {
  srand(time(nullptr));
  int array_1[]{1, 5, 1, 4, 5, 6, 2, 1, 3, 4, 4, 4, 5, 7};
  size_t LENGTH_1 = sizeof(array_1) / sizeof(*array_1);
  int array_2[]{1, 5, 1, 4, 5, 6, 2, 1, 3, 4, 4, 4, 5, 7, 6, 21, 43, 5, 2, 21, 34, 90};
  size_t LENGTH_2 = sizeof(array_2) / sizeof(*array_2);
  int array_3[]{10, 5, 1, 4, 5, 10, 2, 1, 3, 10, 4, 4, 5, 10, 6};
  size_t LENGTH_3 = sizeof(array_3) / sizeof(*array_3);

  // Рандомный массив
  size_t rand_length = rand()%25 + 10;
  int random_array[rand_length];
  for (size_t i = 0; i < rand_length; i++) {
    random_array[i] = rand()%25;
  }

  cout << "Should be 3.6\t --->\t " << array_splitter(LENGTH_1, array_1) << endl;
  cout << "Should be 18.75\t --->\t " << array_splitter(LENGTH_2, array_2) << endl;
  cout << "Should be 4.4\t --->\t " << array_splitter(LENGTH_3, array_3) << endl;
  cout << "Array[" << rand_length << "]{ ";
  for (size_t i = 0; i < rand_length; i++) {
    cout << random_array[i] << ' ';
  }

  cout << "}\nShould be random result ---> " << array_splitter(rand_length, random_array) << endl;
}


int main() {
  test_case_function(array_splitter);

  return 0;
}
