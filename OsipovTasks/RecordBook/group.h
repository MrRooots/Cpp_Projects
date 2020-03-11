#include <iostream>
#include <list>
using namespace std;

/*
TODO:
  1) Операторы ввода-вывода в поток для "зачетки"
  // оператор "-" должен работать по номеру удаляемой зачетки или по имени студента, зачетку которого надо удалить или просто по номеру зачетки?
  2) Операторы + и - для "группы"
*/

class GroupList {
public:
  GroupList();                                            // Конструктор
  GroupList(vector<RecordBook>);                          // Конструктор, принимает вектор зачеток
  // GroupList(RecordBook, ...);                          // По идее принимает переменное кол-во зачеток, но пока не работает :)
  // ~GroupList();                                        // Деструктор, без понятия как его реализовать, ведь у std::list уже есть свой деструктор
  void append(RecordBook);                                // Добавление элемента
  void removeByIndex(size_t);                             // Удаление книжки по номеру
  void removeByName(string);                              // Удаление книжки по имени студента
  void print();                                           // Печать содержимого
  void search(char[str_len]);                             // Поиск по одному из инициалов
  bool isInside(vector<char*>, string);                   // Есть ли элемент в массиве
  bool compare(list<RecordBook>::iterator, RecordBook);    // Сравнение по первой букве фамилии двух зачеток
  void operator+ (RecordBook object) {
    append(object);
  }
  void operator- (RecordBook object) {
    removeByName(object.get_initials()[0]);  // Удалит по фамилии
  }
private:
  list<RecordBook> group_list;
  size_t group_length = 1;
};

/* ------------------------------------------------------------ КОНСТРУКТОРЫ ------------------------------------------------------------ */

// Конструктор по умолчанию
GroupList::GroupList() {
  cout << "**Group Constructed!" << endl;
}

// Конструктор, который принимает вектор зачеток
GroupList::GroupList(vector<RecordBook> toAdd) {
  for (auto record : toAdd) {
    append(record);
  }
}

// // По идее принимает переменное кол-во зачеток, но пока не работает :)
// GroupList::GroupList(RecordBook record, ...) {
//   RecordBook *record_pointers = &record;

//   while (record_pointers) {
//     record_pointers++;
//     append(*record_pointers);
//   }
// }

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
  cout << group << ' ' << record << ' ' << compare_result << endl;      
  if (compare_result == -1) {
    return true;
  }
  return false;
}

// Добавление элемента
void GroupList::append(RecordBook record) {
  // Если список пуст - просто всунем элемент
  if (group_list.size() == 0) {
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
void GroupList::removeByIndex(size_t index) {
  auto my_iterator = group_list.begin();
  advance(my_iterator, --index);
  group_list.erase(my_iterator);
}

// Удаление книжки по имени студента  (Удалит первое найденное совпадение)
void GroupList::removeByName(string initial) {
  for (auto i = group_list.begin(); i != group_list.end(); ++i) {
    if (isInside((*i).get_initials(), initial)) {
      group_list.erase(i);
      break;
    }
  }
}

// Печать содержимого
void GroupList::print() {
  size_t i = 1;

  for (auto cur_record = --group_list.end(); cur_record != group_list.begin(); cur_record--) {
    cout << i++ << "|---";
    (*cur_record).get_full_info();
  }
  cout << i++ << "|---"; ((*group_list.begin()).get_full_info());
}

// Поиск по одному из инициалов
void GroupList::search(char initial[str_len]) {
  for (auto i = group_list.begin(); i != group_list.end(); ++i) {
    if (isInside((*i).get_initials(), initial)) {
      (*i).get_full_info();
    }
  }
}

// Есть ли элемент в массиве
bool GroupList::isInside(vector<char*> array, string toSearch) {
  for (size_t i = 0; i < 3; i++) {
    if (!strcmp(array[i], toSearch.c_str())) {
      return true;
    }
  }
  return false;
}