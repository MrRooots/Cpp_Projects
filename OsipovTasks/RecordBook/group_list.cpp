#include <iostream>
#include <list>
#include <vector>
#include "recordbook.h"
using namespace std;

class GroupList {
public:
  // GroupList();                            // Конструктор
  // ~GroupList();                           // Деструктор
  void append(RecordBook);                // Добавление элемента
  void removeByIndex(size_t);             // Удаление книжки по номеру
  // void removeByName(string);              // Удаление книжки по имени студента (пока нету, так как надо реализовывать двусвязный список)
  void print();                           // Печать содержимого
  void search(char[255]);                 // Поиск по одному из инициалов
  bool isInside(LIST_TYPO, string);       // Есть ли элемент в массиве
  // void sort_me();                         // Отсортирует список по имени/фамилии студента
private:
  list<RecordBook> group_list;
};

// Добавление элемента
void GroupList::append(RecordBook record) {
  group_list.push_back(record);
}

// Удаление книжки по номеру
void GroupList::removeByIndex(size_t index) {
  auto my_iterator = group_list.begin();
  advance(my_iterator, index);
  group_list.erase(my_iterator);
}

// Печать содержимого
void GroupList::print() {
  for (auto cur_record = group_list.begin(); cur_record != group_list.end(); ++cur_record) {
    (*cur_record).get_full_info();
  }
  
}

// Поиск по одному из инициалов
void GroupList::search(char initial[255]) {
  for (auto i = group_list.begin(); i != group_list.end(); ++i) {
    LIST_TYPO temp_list{"", "", ""};
    LIST_TYPO* initials_list = (*i).get_initials();  // Получим массив инициалов
    
    for (size_t i = 0; i < 3; i++) {
      for (size_t l = 0; l < 255; l++) {
        temp_list[i][l] = (*initials_list)[i][l];
      }
    }

    if (isInside(temp_list, initial)) {
      (*i).get_full_info();
    }
  }
  
}

// // Отсортирует список по имени/фамилии студента
// void GroupList::sort_me() {
//   group_list.sort();
//   cout << "Sorted!" << endl;
// }

// Есть ли элемент в массиве
bool GroupList::isInside(LIST_TYPO array, string toSearch) {
  for (size_t i = 0; i < 3; i++) {
    if (array[i] == toSearch) {
      return true;
    }
  }
  return false;
}

int main() {
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

  GroupList current_group;
  RecordBook zero_record, third_record(initials_list, subject_names, dates_list, pass_balls_list, full_balls_list), second_record, first_record;
  current_group.append(zero_record);
  current_group.append(third_record);
  current_group.append(first_record);
  current_group.append(third_record);
  current_group.append(second_record);
  
  // current_group.print();

  return 0;
}