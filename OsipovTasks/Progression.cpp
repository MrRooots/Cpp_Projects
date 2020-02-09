#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Пусть прогрессия задается массивом
    int ar_count, geo_count;
    cout << "Введите кол-во членов арифметической прогрессии: " ; cin >> ar_count;
    cout << "Введите кол-во членов геометрической прогрессии: " ; cin >> geo_count;

    float *arithmetic_array = new float[ar_count];  // Инициализация памяти для динамического массива
    float *geometric_array = new float[geo_count];  // Инициализация памяти для динамического массива
    float result_form = 0, result_sum = 0;

    // Если последовательности не пусты
    if (ar_count > 0 && geo_count > 0) {
      // Заполнение арифметической прогрессии с клавиатуры
      cout << "Арифметическая прогрессия";
      for (int i = 0; i < ar_count; i++) {
        cout << i + 1 << "член: ";
        cin >> arithmetic_array[i];
      };

      cout << endl;

      // Заполнение геометрической прогрессии с клавиатуры
      cout << "Геометрическая прогрессия";
      for (int i = 0; i < geo_count; i++) {
        cout << i + 1 << "член: ";
        cin >> geometric_array[i];
      };

      // Вычисление суммы арифметической прогрессии
      result_form = (( 2 * arithmetic_array[0] + (arithmetic_array[1] - arithmetic_array[0]) * (ar_count - 1) ) / 2) * ar_count;  // Сумма по формуле

      // Последовательное сложение элементов
      for (int i = 0; i <ar_count; i++) {
        result_sum += arithmetic_array[i];
      };

      // Вывод полученных значений
      cout << endl << "Значение по формуле: " << result_form << endl << "Значение последовательного сложения: " << result_sum << endl;

      // Сравнение полученных значений
      if (result_form == result_sum) {
        cout << "Значения равны" << endl << endl;
      } else {
        cout << "Ошибка!" << endl << endl;
      };

      result_form = 0; result_sum = 0;

      // Вычисление суммы геометрической прогрессии
      // Сумма по формуле
      result_form = (geometric_array[0] * (1 - pow(geometric_array[1] / geometric_array[0], geo_count))) / (1 - (geometric_array[1] / geometric_array[0]));

      // Последовательное сложение
      for (int i = 0; i <geo_count; i++) {
        result_sum += geometric_array[i];
      };
      // Вывод полученных значений
      cout << "Значение по формуле: " << result_form << endl << "Значение последовательного сложения: " << result_sum << endl;

      // Сравнение полученных значений
      if (result_form == result_sum) {
        cout << "Значения равны";
      } else {
        cout << "Ошибка!";
      };

    } else {
      cout << "Задана пустая последовательность";
    };

  return 0;
}
