#include <iostream>
using namespace std;

struct element {
 long double temp_handicap;  // Информационное поле (в данном случае постоянно уменьшающееся расстояние между телами)
 element *Next;  // Адрес
};

// Основной класс List
class List {
  element *Head;  // Голова списка
public:
  // Прототипы методов класса
  List() {Head = NULL;}  // Конструктор
  ~List();  // Деструктор
  void Add(long double temp_handicap);  // Добавление элемента
  void Show();  // Вывод всех элементов
};

// Деструктор класса
List::~List() {
  while (Head) {
    element *temp = Head->Next;
    delete Head;
    Head = temp;
  }
}

// Добавление эл-та в список
void List::Add(long double temp_handicap) {
  element *temp = new element;
  temp->temp_handicap = temp_handicap;
  temp->Next = Head;
  Head = temp;
}

// Вывод элементов списка
void List::Show() {
  element *temp=Head;

  while (temp != NULL) {
    cout << temp->temp_handicap << endl;
    temp = temp->Next;
 }
}

int main() {
  // Тестовые данные
  long double handicap = 1000, ball_speed=100, wall_speed=10, wall_coord = 1000, ball_coord = 0, current_time = 1, time_before_reach;
  long double limit = 0.000000000000000000000000000000000000000000000000000001;  // Лимитирование последовательности

  List lst;

  while (handicap > limit) {
		// cout << "|" << time_before_reach << "\t\t|" << wall_coord << "\t\t|" << ball_coord << "\t\t|" <<  handicap << endl;  // Вывод значений
    lst.Add(handicap);  // Добавление вычесленного значения в динамический список

		time_before_reach = wall_coord / ball_speed;  // Время, за которое тело достигнет позиции стены
		wall_coord = wall_speed * time_before_reach;  // Пока тело достигает позиции стена, стена улетает
		ball_coord = ball_speed * time_before_reach;  // Расчет оординаты тела

		handicap = wall_coord;  // Расчет растояния между ними

	}
	cout << "<------------------------------------------------------->" << endl << "ETC." << endl << "<------------------------------------------------------->";

  lst.Show();  // Вывод всех значений (с конца, считая, что последовательность ограничена 0)

  return 0;
}
