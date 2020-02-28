#include <iostream>
using namespace std;

struct Node {
  int value;  // Значение
  Node *pNext;  // Ссылка на следующий элемент должна указывать на первый созданный элемент
};

class Main_List {
private:
  Node *head;  // Инициализация головы списка (пока без значений)
  Node *tail;  // Инициализаця последнего элемента списка
  size_t size;  // Счетчик количества элементов в списке
public:
  // Прототипы
  Main_List();  // Конструктор
  ~Main_List();  // Деструктор
  void append(int element_to_add);
  void print_list();
  size_t length() {return size;};
  void remove(size_t position);
};

// Конструктор
Main_List::Main_List() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

// Деструктор
Main_List::~Main_List() {
  // Пока указатель будет указывать на что-нибудь
  while (head) {
    Node *ptr_to_new_struct = head->pNext;
    delete head;
    head = ptr_to_new_struct;
    size--;
  }
}

// Добавление элемента в список
void Main_List::append(int element_to_add) {
  // Создали указатель типа Node на новую пустую структуру типа Node
  Node *ptr_to_new_struct = new Node;
  ptr_to_new_struct->value = element_to_add;  // Передача значения
  ptr_to_new_struct->pNext = head;  // Переброс указателя
  // Если список не пуст
  if (head) {
    tail->pNext = ptr_to_new_struct;
    tail = ptr_to_new_struct;
    // cout << "HERE";
  } else {
    // Иначе создается первый элемент
    head = ptr_to_new_struct;
    tail = ptr_to_new_struct;
  }
  size++;
}

// Печать элементов списка
void Main_List::print_list() {
  Node *current_structure = head;  // current_structure теперь указывает на последнюю созданную структуру

  for (size_t i = 0; i < size; i++) {
    cout << current_structure->value << ' ';
    current_structure = current_structure->pNext;
  }
}

// Удаление элемента по индексу (номеру)
void Main_List::remove(size_t word_count) {
  Node *current_pointer = head;
  Node *previous_pointer = nullptr;

  while (size > 0) {
    Main_List::print_list(); cout << endl;

    for (size_t i = 1; i < word_count+1; i++) {
      if (i == word_count - 1) {
        previous_pointer = current_pointer;
      }
      current_pointer = current_pointer->pNext;
    }

    if (previous_pointer->pNext == head) {
      head = previous_pointer->pNext->pNext;
    }

    previous_pointer->pNext = current_pointer;
    size--;
  }
}



// Список хранит значение и ссылку на следуюющий элемент
int main() {
  // Инициализируем объект класса Main_List
  Main_List lst;  // При этом *head = nullptr {1}
  size_t count; cout << "Enter count of elements: "; cin >> count;
  size_t word_count; cout << "Enter count of words: "; cin >> word_count;
  // word_count--;

  // Заполнение списка
  for (int i = 0; i < count; i++) {
    lst.append(i+1);
  }

  // size_t const length = lst.length();  // Постоянная величина длины списка

  // lst.remove(0);
  size_t t = 0; // Счетчик удаления элементов

  lst.remove(word_count);

  lst.print_list();
  exit(0);  // с return почему-то не выходит)
}
