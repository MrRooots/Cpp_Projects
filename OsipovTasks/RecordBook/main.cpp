#include <iostream>
#include <string>
#include "recordbook.h"   // Класс зачетка
#include "group.h"        // Класс группа
using namespace std;

// Repl.it link --> https://repl.it/@MrRooots/RecordBooksClass
int main() {
  size_t choice;
  string path = "file.bin";  // Путь сохранение
  char initials_list[3][255]={"Marek", "Nikita", "Dmitrievich"};
  char subject_names[6][255]={
    "Mathematical Analysis", "Algebra and Geometry", "Basics of programming",
    "English Language", "Effecient Communication", "Physical Education"
  };
  char dates_list[6][255]={
    "01.01.2020", "02.01.2020", "03.01.2020",
    "04.01.2020", "05.01.2020", "06.01.2020"
  };
  size_t pass_balls_list[3]={1, 0, 1};
  float full_balls_list[3]={100, 101, 102};
  RecordBook my_record;

  cout << "Do you have a save file(0/1): "; cin >> choice;
  if (choice == 0) {
    RecordBook new_my_record(initials_list, subject_names, dates_list, pass_balls_list, full_balls_list);  // С предустановкой;
    my_record = new_my_record;
  } else {  // Файл с сохранением есть -> считаем из него данные
    my_record = my_record.read_binary(path, my_record);  // Считаем информацию из имеющегося файла в текущий объект
    cout << "This infarmation was read from file:\n";
    my_record.get_full_info();  // Печать информации
  }

  // Цикл с выбором действий
  cout << "Exit - 0\nSave - 1\nRead - 2\nPrint - 3\nChange - 4\nTest Save/Find Student\n";
  while (true) {
    cout << "Your choice: "; cin >> choice;
    if (choice == 0) {return 0;}                                            // Выход
    if (choice == 1) {my_record.save_binary(path, my_record);}              // Сохранение
    if (choice == 2) {my_record = my_record.read_binary(path, my_record);}  // Восстановление
    if (choice == 3) {my_record.get_full_info();}                           // Вывод
    // Изменение данных
    if (choice == 4) {
      size_t choice;
      cout << "What type of data do you want to change: 1)Balls 2)String info\nYour choice: "; cin >> choice;
      if (choice == 1) {  // Численных
        size_t info_to_change; cout << "Enter a new information: "; cin >> info_to_change;
        my_record.change_information_digits(info_to_change);
      }
      if (choice == 2) {  // Строковых
        char info_to_change[255];
        cout << "Enter a new information: "; cin >> info_to_change;

        my_record.change_information_string(info_to_change);
      }
    }
    if (choice == 5) {
      string to_find = "Nikita";  // Инициал по которому искать
      RecordBook first_my_record(initials_list, subject_names, dates_list, pass_balls_list, full_balls_list);  // С предустановкой;
      RecordBook second_my_record;  // Конструктор без параметров
      // RecordBook third_my_record = my_record.read_binary(path, my_record);  // Добавление считанного студента - тест
      Group current_group;
      current_group.append_student(first_my_record);
      current_group.append_student(second_my_record);
      // current_group.append_student(third_my_record);
      current_group.find_student(to_find);  // Поиск студента
    }
    // ---------------------------------------------------- Testing functions --------------------------------------------------------------
    if (choice == 6) {  // Обнуление текущего объекта
      RecordBook new_my_record;
      my_record = new_my_record;
    }
    if (choice == 7) {
      RecordBook new_my_record(initials_list, subject_names, dates_list, pass_balls_list, full_balls_list);  // С предустановкой;
      my_record = new_my_record;
    }
    if (choice == 8) {  // Отчистка экрана
      system("cls");
      cout << "Exit - 0\nSave - 1\nRead - 2\nPrint - 3\nChange - 4\nTest Save/Find Student\n";
    }
    // ------------------------------------------------------------------------------------------------------------------------------------
  }
}
