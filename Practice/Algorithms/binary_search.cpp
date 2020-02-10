#include <iostream>
#include <ctime>
using namespace std;

// функция с алгоритмом двоичного поиска
int binare_search(int arr[], int left_index, int right_index, int element_to_search) {
	int half_index = 0;  // Серединный индекс
	while (true) {
		half_index = (left_index + right_index) / 2;

		if (element_to_search < arr[half_index]) {
      right_index = half_index - 1;
    } else if (element_to_search > arr[half_index]) {
      left_index = half_index + 1;
    }	else {
      return half_index;
    }
		if (left_index > right_index) {
      return -1;
    }
	}
}aaa

int main() {
	int length; cout << "Enter a length of the array: "; cin >> length;
	int array[length];
	int element_to_search = 0, index = 0;
	srand(time(nullptr));  // Немного рандомности при заполнении

	// Опцианольное заполнение массива
	for (int i = 0; i < length; i++) {
		if (rand()%1000 > 500) {
			array[i] = i+1;
		} else {
			array[i] = i*4;
		}

	}

	cout << "Enter a number to find: "; cin >> element_to_search;

	index = binare_search(array, 0, length, element_to_search);

	if (index >= 0) {
    cout << "The index of the " << element_to_search << " number is: " << index;
  }
	else
		cout << "Nothing was found!";

	return 0;
}
