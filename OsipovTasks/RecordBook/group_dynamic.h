struct GroupElement {
  RecordBook object;      // Поле будет содержать предназначенный ему объект класса RecordBook
  GroupElement *toNext;   // Указатель на следующую структуру
  GroupElement *toPrev;   // Указатель на предыдущую структуру
};

class GroupList {
public:
  GroupList();                            // Конструктор
  ~GroupList();                           // Деструктор
  void append(RecordBook);                // Добавление элемента
  void removeByIndex(size_t);             // Удаление книжки по номеру
  void removeByName(string);              // Удаление книжки по имени студента (пока нету, так как надо реализовывать двусвязный список)
  void print();                           // Печать содержимого
  void search(char[255]);                 // Поиск по одному из инициалов
  bool isInside(LIST_TYPO, string);       // Есть ли элемент в массиве
  void sort_me();                         // Отсортирует список по имени/фамилии студента
private:
  GroupElement *Head;                     // Голова списка типа GroupElement
  size_t length;
};

// Конструктор
GroupList::GroupList() {
  Head = nullptr;
}

// Деструктор
GroupList::~GroupList() {
  while (Head) {
    GroupElement *temp = Head->toNext;
    delete Head;
    Head = temp;
  }
}

// Добавление элемента
void GroupList::append(RecordBook object) {
  GroupElement *toNew = new GroupElement;        // Содаем новую структуру, доступную по указателю toNew
  toNew->object = object;                        // Новой структуре передаем новый объект
  toNew->toNext = Head;
  Head = toNew;
  length++;
}

// Печать содержимого
void GroupList::print() {
  GroupElement *temp = Head;
  size_t current_index = 1;

  while (temp != NULL) {
    cout << "|--- " << current_index++ << ": ";  // Вывод номера зачетки
    temp->object.get_full_info();  // Вызываем метод печати каждого элемента, хранящегося в списке
    temp = temp->toNext;
  }
}

// Поиск зачетки по одному из инициалов --> распечатает первую найденную
void GroupList::search(char toSearch[255]) {
  GroupElement *temp = Head;

  while (temp != NULL) {
    LIST_TYPO list{"", "", ""};
    LIST_TYPO* initials_list = temp->object.get_initials();  // Получим массив инициалов

    for (size_t i = 0; i < 3; i++) {
      for (size_t l = 0; l < 255; l++) {
        list[i][l] = (*initials_list)[i][l];
      }
    }
    if (isInside(list, toSearch)) {  // Если нашли
      cout << "--------| Searching completed! |--------" << endl;
      temp->object.get_full_info();
    }
    temp = temp->toNext;
  }
}

// Вспомогательная функция для нахождения эллемента в массиве
bool GroupList::isInside(LIST_TYPO list, string toSearch) {
  for (size_t i = 0; i < 3; i++) {
    if (list[i] == toSearch) {
      return true;
    }
  }
  return false;
}

// Поиск и удаление зачетной книжки из списка по индексу (1..n)
void GroupList::removeByIndex(size_t index) {
  GroupElement *temp = Head;
  GroupElement *prev = nullptr;
  size_t current_index = 1;

  if (index == 1) {
    Head = Head->toNext;
  } else {
    while (temp != NULL) {
      if (current_index == index - 1) {
        prev = temp;
      } else if (current_index == index + 1) {
        delete prev->toNext;
        prev->toNext = temp;
      }
      temp = temp->toNext;
      current_index++;
    }
  }
}

// Удаление зачетки по имени/фамилии
void GroupList::removeByName(string name) {

}

// Отсортирует список по имени/фамилии студента
void GroupList::sort_me() {

}