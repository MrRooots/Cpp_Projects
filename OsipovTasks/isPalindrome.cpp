#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Файл, который читаем, должен лежать на одном уровне с исполняемым файлом
int main() {
  ifstream file("phrase_pal.txt");  // file - объект потока ifstream
  string line;  // То, куда считываем из файла

  // Если смогли считать строку с файла
  if (getline(file, line)) {
    // cout << "Line from file: " << line;
    size_t line_length = line.length();  // Длина полученной строки
    string reversed_line = "";

    // Перевернем исходную строку
    for (size_t index = 0; index < line_length; index++) {
      reversed_line += line[line_length - index - 1];
    }

    // Сравним обе строки
    for (size_t index = 0; index < line_length; index++) {
      // Если не совпал хотя-бы один символ
      if (line[index] != reversed_line[index]) {
        cout << "Not palindrome!";
        return 0;
      }
    }

    cout << "Palindrome!";
    return 0;

  } else {
    cout << "Error while reading file {file_name}" << endl;  // Не смогли считать
    return 0;
  }
}
