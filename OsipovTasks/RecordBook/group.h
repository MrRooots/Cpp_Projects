#include <iostream>
#include <cstdarg>
#include <list>
using namespace std;

class GroupList {
public:
  GroupList(size_t, RecordBook, ...);                     // По идее принимает переменное кол-во зачеток, но требует их количество, как первый параметр
  GroupList(vector<RecordBook>);                          // Конструктор, принимает вектор зачеток
  ~GroupList();                                           // Деструктор
  void append(RecordBook);                                // Добавление элемента
  void remove(size_t);                                    // Удаление книжки по номеру
  void remove(string);                                    // Удаление книжки по имени студента
  void print();                                           // Печать содержимого
  void search(char[str_len]);                             // Поиск по одному из инициалов или по трем сразу (без пробелов)
  bool isInside(vector<char*>, string);                   // Есть ли элемент в массиве
  bool compare(list<RecordBook>::iterator, RecordBook);   // Сравнение по первой букве фамилии двух зачеток
  void operator+ (RecordBook object) {                    // Просто добавит зачетку в группу
    append(object);
  }
  void operator- (RecordBook object) {                    // Удалит первое совпадение по иниациалам из группы
    vector<char*> init = object.get_initials();
    string to_remove = "";
    for (char* x : init) {
      to_remove += x;
    }
    remove(to_remove);
  }
private:
  list<RecordBook> group_list;
  size_t group_length = 0;
};

/* ------------------------------------------------------------ КОНСТРУКТОРЫ ------------------------------------------------------------ */

// Конструктор, который принимает вектор зачеток
GroupList::GroupList(vector<RecordBook> toAdd) {
  for (auto record : toAdd) {
    append(record);
  }
}

// По идее принимает переменное кол-во зачеток, но требует их количество, как первый параметр
GroupList::GroupList(size_t count, RecordBook records, ...) {
  RecordBook* object = &records;
  for (size_t i = 0; i < count; i++) {
    append(*object); ++object;
  }
}

// Деструктор
GroupList::~GroupList() {
  group_list.clear();
  delete &group_list;
  cout << "Destructed!" << endl;
}

/* ------------------------------------------------------------ МЕТОДЫ ------------------------------------------------------------ */

// Сортировка по ФИО
bool GroupList::compare(list<RecordBook>::iterator group_object, RecordBook record_object) {
  string group = "";
  vector<char*> initials = (*group_object).get_initials();
  for (auto initial : initials) {
    group += initial;
  }
  string record = "";
  initials = (record_object).get_initials();
  for (auto initial : initials) {
    record += initial;
  }
  int compare_result = strcmp(group.c_str(), record.c_str());  // Фамилии
  if (compare_result == -1) {
    return true;
  }
  return false;
}

// Добавление элемента
void GroupList::append(RecordBook record) {
  // Если список пуст - просто всунем элемент
  group_length++;
  if (group_length == 1) {
    group_list.push_back(record);
  } else {
    for (auto i = group_list.begin(); i != group_list.end(); ++i) {
      if (compare(i, record)) {  // Получаем результат сравнения (можно ли засунуть перед итерируемым объектом)
        group_list.insert(i, record);
        break;
      } else if (i == --group_list.end()) {
        group_list.push_back(record);
        break;
      }
    }
  }
}

// Удаление книжки по номеру
void GroupList::remove(size_t index) {
  auto my_iterator = group_list.begin();
  advance(my_iterator, --index);
  group_list.erase(my_iterator);
  group_length--;
}

// Удаление книжки по имени студента  (Удалит первое найденное совпадение)
void GroupList::remove(string initial) {
  for (auto i = group_list.begin(); i != group_list.end(); ++i) {
    if (isInside((*i).get_initials(), initial)) {
      group_list.erase(i);
      group_length--;
      break;
    }
  }
}

// Печать содержимого
void GroupList::print() {
  size_t i = group_length;
  for (auto cur_record = group_list.rbegin(); cur_record != group_list.rend(); ++cur_record) {
    cout << i-- << "|---";
    (*cur_record).get_full_info();
  }
}

// Поиск по одному из инициалов или по трем сразу (без пробелов)
void GroupList::search(char initial[str_len]) {
  for (auto i = group_list.begin(); i != group_list.end(); ++i) {
    if (isInside((*i).get_initials(), initial)) {
      (*i).get_full_info();
    }
  }
}

// Есть ли элемент в массиве
bool GroupList::isInside(vector<char*> array, string toSearch) {
  string initial_line = "";
  for (char* x : array) {initial_line += x;}
  // Проверка полного совпадения ФИО
  if (!strcmp(initial_line.c_str(), toSearch.c_str())) {
    group_length--;
    return true;
  }
  // Проверка совпадения хотя бы одного инициала
  for (size_t i = 0; i < 3; i++) {
    if (!strcmp(array[i], toSearch.c_str())) {
      return true;
    }
  }
  return false;
}