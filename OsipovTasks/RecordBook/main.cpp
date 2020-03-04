#include <iostream>
#include <string>
#include "recordbook.h"           // Класс зачетка
#include "group_dynamic.h"        // Класс группа как динамический односвязный список
using namespace std;


// Repl.it link --> https://repl.it/@MrRooots/RecordBooksClass
int main() {
  size_t choice;
  string path = "file.bin";  // Путь сохранение
  char initials_list[3][255]{"Marek", "Nikita", "Dmitrievich"};
  char subject_names[6][255]{
    "Mathematical Analysis", "Algebra and Geometry", "Basics of programming",
    "English Language", "Effecient Communication", "Physical Education"
  };
  char dates_list[6][255]{
    "01.01.2020", "02.01.2020", "03.01.2020",
    "04.01.2020", "05.01.2020", "06.01.2020"
  };
  size_t pass_balls_list[3]{1, 0, 1};
  float full_balls_list[3]{100, 101, 102};

  RecordBook my_record;
  GroupList current_group;

  cout << "Do you have a save file(0/1): "; cin >> choice;
  if (choice == 0) {
    RecordBook new_my_record(initials_list, subject_names, dates_list, pass_balls_list, full_balls_list);
    my_record = new_my_record;
  } else {                                                // Файл с сохранением есть -> считаем из него данные
    my_record = my_record.read_binary(path, my_record);   // Считаем информацию из имеющегося файла в текущий объект
    cout << "This infarmation was read from file:\n";
    my_record.get_full_info();                            // Печать информации
  }

  // Цикл с выбором действий
  cout << "Exit - 0\nSave - 1\nRead - 2\nPrint - 3\nChange - 4\nTest Find Student - 5\nEmpty record - 6\n";
  while (true) {
    cout << "Your choice: "; cin >> choice;
    switch (choice) {
      case 0:                                                          // Выход
        return 0;
        break;                                               
      case 1:                                                          // Сохранение
        my_record.save_binary(path, my_record); 
        break;                 
      case 2:                                                          // Восстановление
        my_record = my_record.read_binary(path, my_record);
        break;     
      case 3:                                                          // Вывод
        my_record.get_full_info();
        break;
      case 4: {
        size_t choice;
        cout << "What type of data do you want to change: 1)Balls 2)String info\nYour choice: "; cin >> choice;
        switch (choice) {
          case 1:  // Численных
            size_t numbers_to_change;
            cout << "Enter a new information: "; cin >> numbers_to_change;
            my_record.change_information_digits(numbers_to_change);
            break;
          case 2:  // Строковых
            char info_to_change[255];
            cout << "Enter a new information: "; cin >> info_to_change;
            my_record.change_information_string(info_to_change);
            break;
        }
        break;
      }
      case 5: {
        RecordBook zero_record, first_record, second_record, third_record(initials_list, subject_names, dates_list, pass_balls_list, full_balls_list);  // С предустановкой;;

        current_group.append(zero_record);
        current_group.append(third_record);
        current_group.append(first_record);
        current_group.append(third_record);
        current_group.append(second_record);

        current_group.print();

        size_t index; cout << "Enter a number to remove: "; cin >> index;
        current_group.removeByIndex(index);
        current_group.print();
        break;
      }
      case 6: {  // Обнуление текущего объекта
        RecordBook empty_record;
        my_record = empty_record;
        break;
      }
    }
  }
}
