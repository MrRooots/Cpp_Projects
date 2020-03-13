#include <iostream>
#include "recordbook.h"             // Класс зачетка
#include "group.h"                  // Класс группа как stl контейнер
using namespace std;


// Repl.it link --> https://repl.it/@MrRooots/RecordBooksClass
int main() {
  size_t choice;
  string path = "file.bin";  // Путь сохранение
  char initials_list[ball_init_len][str_len]{"Marek", "Nikita", "Dmitrievich"};
  char subject_names[sub_date_len][str_len]{
    "Mathematical Analysis", "Algebra and Geometry", "Basics of programming",
    "English Language", "Effecient Communication", "Physical Education"
  };
  char dates_list[sub_date_len][str_len]{
    "01.01.2020", "02.01.2020", "03.01.2020",
    "04.01.2020", "05.01.2020", "06.01.2020"
  };
  size_t pass_balls_list[ball_init_len]{1, 0, 1};
  float full_balls_list[ball_init_len]{100, 101, 102};

  RecordBook my_record;

  // Восстановление из существующего файла
  cout << "Do you have a save file(0/1): "; cin >> choice;
  if (choice == 0) {
    RecordBook new_my_record(initials_list, subject_names, dates_list, pass_balls_list, full_balls_list);
    my_record = new_my_record;
  } else {  // Файл с сохранением есть -> считаем из него данные
    my_record = my_record.read_binary(path);
    cout << "This infarmation was read from file:\n";
    my_record.get_full_info();
  }
  // Цикл с выбором действий
  cout << "Exit - 0\nSave - 1\nRead - 2\nPrint - 3\nChange - 4\nTest Find Student - 5\nEmpty record - 6\n";
  while (true) {
    cout << "Your choice: "; cin >> choice;
    switch (choice) {
      case 0:                                                          // Выход
        return 0;
      case 1:                                                          // Сохранение
        my_record.save_binary(path); break; 
      case 2:                                                          // Восстановление
        my_record = my_record.read_binary(path); break;
      case 3:                                                          // Вывод
        my_record.get_full_info(); break;
      case 4: {                                                        // Изменение данных
        size_t choice;
        cout << "What type of data do you want to change: 1)Balls 2)String info\nYour choice: "; cin >> choice;
        switch (choice) {
          case 1:  // Численных
            size_t numbers_to_change;
            cout << "Enter a new information: "; cin >> numbers_to_change;
            my_record.change_information_digits(numbers_to_change);
            break;
          case 2:  // Строковых
            char info_to_change[str_len];
            cout << "Enter a new information: "; cin >> info_to_change;
            my_record.change_information_string(info_to_change);
            break;
        }
        break;
      }
      case 5: {                                                        // Тест работы группы
        char initials_list_0[ball_init_len][str_len]{"AMarek", "Nikita", "Dmitrievich"};
        char initials_list_1[ball_init_len][str_len]{"Marek", "ANikita", "Dmitrievich"};
        char initials_list_2[ball_init_len][str_len]{"Marek", "Nikita", "ADmitrievich"};
        RecordBook  first_record, 
                    second_record(initials_list, subject_names, dates_list, pass_balls_list, full_balls_list),
                    third_record(initials_list_1, subject_names, dates_list, pass_balls_list, full_balls_list),
                    fourth_record(initials_list_2, subject_names, dates_list, pass_balls_list, full_balls_list),
                    fifth_record(initials_list_0, subject_names, dates_list, pass_balls_list, full_balls_list);
        
        // vector<RecordBook> toAdd = {first_record, fifth_record, third_record, second_record, fourth_record, first_record, fourth_record, third_record};
        // GroupList current_group(toAdd);

        GroupList current_group(8, first_record, fifth_record, third_record, second_record, fourth_record, first_record, fourth_record, third_record);
        current_group.print();
        break;
      }
      case 6: {                                                        // Обнуление текущего объекта
        RecordBook empty_record;
        my_record = empty_record;
        break;
      }
    }
  }
}
