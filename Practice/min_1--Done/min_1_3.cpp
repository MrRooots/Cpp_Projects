// Аккумуляция вводимых пользователем значений, удовлетворяющих заданному предикату, и вывод результата на экран.
// Если не указан результат в случае отсутствия удовлетворяющих предикату введённых значений, то возвращать нуль.
// Функции min и max доступны при подключении заголовочного файла algorithm.

// Задание: Сумма синусов чисел, не превосходящих по модулю половину числа пи.

/* Remastered */

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>

using namespace std;

int main() {
  double number, temp_sum = 0;

  for (double x; cin >> number;) {
    if (abs(number) <= M_PI_2) {
      temp_sum += sin(number);
      cout << "Current sum is: " << temp_sum << endl;
    }
  };
  return 0;
}
