#include <iostream>
#include <cstddef>
#include <cstring>
using namespace std;

// Функция для получения длины строки, переданной в функцию
size_t get_length(char const line[]) {
  size_t length = 0, i = 0;

  while (line[i] != '\0') {
    length++; i++;
  }

  return length;
}

// Как только нашелся суффикс, ВСЕ, что за им должно быть подстрокой!!!
// Функция разбора строки и поска в ней, вернет true, если найдет
bool search_in_line(char const string[], char suffix, char substring[]) {
  size_t string_length = get_length(string), substring_length = get_length(substring);
  bool flag = true;

  // Номер строки в которой нашлась заданная подстрока в суффиксе(?), начинающимся с заданного символа.
  // Проход по нуль терминированной строке, пока не найдутся нужные штуки
  for (size_t i = 0; i < string_length; i++) {
    // Если совпала буква суффикса и оставшаяся длина строки вместит в себя подстроку
    if (string[i] == suffix && (substring_length + i + 1) == string_length) {
      // cout << string << endl;
      for (size_t j = i+1; j < string_length; j++) {
        // cout << string[j] << ' ' << substring[j-i-1] << endl;
        if (string[j] != substring[j-i-1]) {
          flag = false;
          break;
        }
      }
      if (flag) { return true;}
    }
    flag = true;
  }

  return false;
}

// возвращать номер первой строки
// в которой нашлась заданная подстрока в суффиксе
// начинающимся с заданного символа
int find_suffix(char const * const lines_array[], char suffix, char substring[]) {
  size_t i = 0;
  int index_to_return = -1;

  // Цикл прохода по массиву, пока не попадется нулевой указатель
  while (lines_array[i] != nullptr) {
    if (search_in_line(lines_array[i], suffix, substring)) {
      return i+1;
    }
    i++;
  }

  return index_to_return;  // Индекс найденной строки, иначе -1
}

bool test_function() {
  // Нуль терминированный массив строк
  char const * const lines_array[]{
    "A line",             // 1
    "Another line",       // 2
    "!@#$^!%",            // 3
    "A more-more lines",  // 4
    "Lines too",          // 5
    "More line",          // 6
    "a line",             // 7
    "some chars here",    // 8
    nullptr
  };

  char substring[] = "re lines", substring_1[] = "re line", substring_2[] = "ars here";  // Подстрока
  char suffix = 'o', suffix_1 = 'o', suffix_2 = 'h';  // Суффикс

  int result = find_suffix(lines_array, suffix, substring);  // Результат поиска
  int result_1 = find_suffix(lines_array, suffix_1, substring_1);  // Результат поиска
  int result_2 = find_suffix(lines_array, suffix_2, substring_2);  // Результат поиска

  if (result == 4 and result_1 == 6 and result_2 == 8) {
    cout << "First result(4): " << result << "\nSecond result(6): " << result_1 << "\nSecond result(8): " << result_2 << endl;
    return true;
  } else {
    return false;
  }

}


// Точка входа
int main() {

  if (test_function()) {
    cout << "Successful!";
  } else {
    cout << "Failed!";
  }

  return 0;
}
