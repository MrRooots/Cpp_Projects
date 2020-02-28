#include <iostream>
#include <vector>  // Реализация массива
using namespace std;

// Класс група - содержит массив зачеток - объектов класса RecordBook
class Group {
public:
  // Добавление студента в список
  void append_student(RecordBook);
  // Вывод информации о студентах в группе (всех)
  void get_group_list();
  // Вывод информации о студентах в группе (по индексу)
  void get_group_list(size_t);
  // Поиск студента по ФИО
  void find_student(string);
  // Определяет встречается ли элемент в принятом массиве
  bool is_inside(LIST_TYPO, string);

private:
  vector<RecordBook> group_list;  // Вектор объектов класса RecordBook
  size_t length = 0;              // Размер группы
};

// Добавление студента в список
void Group::append_student(RecordBook record) {
  group_list.push_back(record);
  length++;
}

// Вывод информации о студентах в группе (всех)
void Group::get_group_list() {
  for (size_t i = 0; i < length; i++) {
    group_list[i].get_full_info();
  }
}

// Вывод информации о студентах в группе (по индексу)
void Group::get_group_list(size_t index) {
  group_list[index].get_full_info();
}

// Поиск студента по ФИО
void Group::find_student(string initials) {
  // Полученные инициалы текущего студента
  for (size_t i = 0; i < length; i++) {
    LIST_TYPO list{"", "", ""};
    LIST_TYPO* initials_list = group_list[i].get_initials();  // Получили ФИО текущего студента

    for (size_t i = 0; i < 3; i++) {
      for (size_t l = 0; l < 255; l++) {
        list[i][l] = (*initials_list)[i][l];
      }
    }
    if (is_inside(list, initials)) {  // Если нашли
      get_group_list(i);
      break;
    }
  }
}

// Определяет встречается ли элемент в принятом массиве
bool Group::is_inside(LIST_TYPO list, string element) {
  for (size_t i = 0; i < 3; i++) {
    if (list[i] == element) {
      return true;
    }
  }
  return false;
}
