#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
using namespace std;

// Написать программу, моделирующую страничку зачетной книжки студента 1 курса 1 текущего семестра. +
// Зачетная книжка содержит данные о ФИО студента, названиях  зачетов и экзаменов с полученными оценками и датами. +
// Заполнить страничку своими данными, записать ее в двоичный файл. +
// Прочитать эти данные для проверки правильности и вывести в стандартный поток вывода.

class RecordBook {
public:
  // Прототипы функций
  // Пустой конструктор по умолчанию
  RecordBook() {};
  // Прототип конструктора с параметрами
  RecordBook( char* name, char* surname, char* middle_name,
              char* date_1, char* date_2, char* date_3, char* date_4, char* date_5, char* date_6,
              char* name_1, char* name_2, char* name_3, char* name_4, char* name_5, char* name_6,
              float ball_1, float ball_2, float ball_3,
              bool ball_4, bool ball_5, bool ball_6);
  void save_binary(string path, RecordBook object);
  void read_file(string path);
  void format_print();
private:
  // Переменные класса
  char *name, *surname, *middle_name;  // ФИО
  char *date_1, *date_2, *date_3, *date_4, *date_5, *date_6;  // Дата
  char *name_1, *name_2, *name_3, *name_4, *name_5, *name_6;  // Названия экзаменов
  float ball_1, ball_2, ball_3;  // Баллы за три экзамена
  bool ball_4, ball_5, ball_6;  // Зачеты
};

// Конструктор с параметрами
RecordBook::RecordBook( char* name, char* surname, char* middle_name,
            char* date_1, char* date_2, char* date_3, char* date_4, char* date_5, char* date_6,
            char* name_1, char* name_2, char* name_3, char* name_4, char* name_5, char* name_6,
            float ball_1, float ball_2, float ball_3,
            bool ball_4, bool ball_5, bool ball_6) {
  this->name = name; this->surname = surname; this->middle_name = middle_name;
  this->date_1 = date_1; this->date_2 = date_2; this->date_3 = date_3; this->date_4 = date_4; this->date_5 = date_5; this->date_6 = date_6;
  this->name_1 = name_1, this->name_2 = name_2, this->name_3 = name_3;
  this->ball_1 = ball_1, this->ball_2 = ball_2, this->ball_3 = ball_3;
  this->name_4 = name_4, this->name_5 = name_5, this->name_6 = name_6;
  this->ball_4 = ball_4, this->ball_5 = ball_5, this->ball_6 = ball_6;
}

// Форматированный вывод всех данных класса
void RecordBook::format_print() {
  cout << "\nStudent initials: " << this->surname << ' ' << this->name << ' ' << this->middle_name << '\n';
  cout << "Date\t\tSubject\t\t\t\tResult\n";
  cout << this->date_1 << "\t" << this->name_1 << "\t\t" << this->ball_1 << '\n';
  cout << this->date_2 << "\t" << this->name_2 << "\t\t" << this->ball_2 << '\n';
  cout << this->date_3 << "\t" << this->name_3 << "\t\t" << this->ball_3 << '\n';
  if (this->ball_4) {
    cout << this->date_4 << "\t" << this->name_4 << "\t\t" << "Success" << '\n';
  } else {
    cout << this->date_4 << "\t" << this->name_4 << "\t\t" << "Failure" << '\n';
  }
  if (this->ball_5) {
    cout << this->date_5 << "\t" << this->name_5 << "\t\t" << "Success" << '\n';
  } else {
    cout << this->date_5 << "\t" << this->name_5 << "\t\t" << "Failure" << '\n';
  }
  if (this->ball_6) {
    cout << this->date_6 << "\t" << this->name_6 << "\t\t" << "Success" << '\n';
  } else {
    cout << this->date_6 << "\t" << this->name_6 << "\t\t" << "Failure" << '\n';
  }
}


// Сохранение объекта класса в бинарный файл
void RecordBook::save_binary(string path, RecordBook object) {
  ofstream file;  // Объект file класса ofstream
  file.open(path, ios::binary);  // Открываем файл по пути path, в противном случае создадим новый

  if (!file.is_open()) {  // Если не смогли открыть файл
    cout << "Error while reading or creating file!";
  } else {
    cout << "File opened successfuly!";
    file.write((char*)&object, sizeof(RecordBook));  // Запись целого объекта, путем передачи ссылки на него, приведенной к типу char
    cout << "\nWriting is done!\n";
  }
  file.close();
}

// Чтение из бинарного файла
void RecordBook::read_file(string path) {
  ifstream file;
  file.open(path, ios::binary);
  RecordBook object;  // Пустой объект для записи в НЕГО из файла

  if (!file.is_open()) {
    cout << "File with name " << path << " does not exist!";
  } else {
    cout << "File is opened successfuly!\n";

    // Запишем то, что считали из файла в объект my_record_read
    file.read((char*)&object, sizeof(RecordBook));
    object.format_print();  // Вывод всех считанных данных)
  }
  file.close();
}

int main() {
  // Инициализация объекта my_record класса RecordBook
  RecordBook my_record(
    "Ivan", "Ivanov", "Ivanovich",
    "01.01.2020", "02.01.2020", "03.01.2020", "04.01.2020", "05.01.2020", "06.01.2020",
    "Mathematical Analysis", "Algebra and Geometry", "Basics of programming",
    "English Language", "Effecient Communication", "Physical Education",
    100.0, 150.0, 1020.0,
    true, true, true
  );
  string path; cout << "Enter a file name with extension: "; cin >> path;  // Ввод имя файла, в который будет сохранен объект класса
  size_t choice;

  cout << "Exit - 0\nSave - 1\nRead - 2\n";

  while (true) {
    cin >> choice;
    if (choice == 1) {
      my_record.save_binary(path, my_record);  // Запись файла по пути
      // my_record.format_print();
    }
    if (choice == 2) {
      my_record.read_file(path);  // Чтение файла
    }
    if (choice == 0) {
      return 0;
    }
  }
}
