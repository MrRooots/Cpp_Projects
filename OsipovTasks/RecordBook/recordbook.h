#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const size_t str_len = 255;         // Длина самих строк в массивах
const size_t sub_date_len = 6;      // Длина массивов для предметов и дат
const size_t ball_init_len = 3;     // Длина массивов под баллы и инициалы

class RecordBook {
public:
  RecordBook();                                                                       // Конструктор по умолчанию
  RecordBook(char[][str_len], char[][str_len], char[][str_len], size_t[], float[]);   // Конструктор с параметрами
  vector<char*> get_initials();                                                       // Возврат пользовательского типа - массива инициалов
  void get_full_info();                                                               // Вывод всей информации о студенте
  void save_binary(string);                                                           // Сохранение в файл
  RecordBook read_binary(string);                                                     // Чтение из файла
  void change_information_string(char[str_len]);                                      // Изменение строковых данных
  void change_information_digits(size_t);                                             // Изменение числовой инф-ии
  void operator=(const RecordBook& object) {                                          // Перегрузка опретаора "="
    for (size_t i = 0; i < 3; i++) {
      strcpy(this->initials[i], object.initials[i]);
      this->pass_balls[i] = object.pass_balls[i];
      this->full_balls[i] = object.full_balls[i];
    }
    for (size_t i = 0; i < 6; i++) {
      strcpy(this->subject_names[i], object.subject_names[i]);
      strcpy(this->dates[i], object.dates[i]);
    }
  }

private:
  char initials[ball_init_len][str_len];        // Инициалы
  char subject_names[sub_date_len][str_len];    // Названия предметов
  char dates[sub_date_len][str_len];            // Даты
  size_t pass_balls[ball_init_len];             // Зачетные баллы
  float full_balls[ball_init_len];              // Числовые баллы
};

/* ------------------------------------------------------------ КОНСТРУКТОРЫ ------------------------------------------------------------ */

// Конструктор по умолчанию
RecordBook::RecordBook() {
  // Инициалы
  char initials[3][str_len] = {"Ivanov", "Ivan", "Ivanovich"};
  
  // Даты
  char dates[6][str_len] = {
    "01.01.2020", "02.01.2020", "03.01.2020",
    "04.01.2020", "05.01.2020", "06.01.2020"};

  // Предметы
  char subject_names[6][str_len] = {
    "Mathematical Analysis", "Algebra and Geometry", "Basics of programming",
    "English Language", "Effecient Communication", "Physical Education"};
  
  // Баллы
  size_t pass_balls[3]={0, 0, 0}; 
  float full_balls[3]={0, 0, 0};

  // Заполнение
  for (size_t i = 0; i < 6; i++) {
    strcpy(this->subject_names[i], subject_names[i]);
    strcpy(this->dates[i], dates[i]);
  }

  for (size_t i = 0; i < 3; i++) {
    strcpy(this->initials[i], initials[i]);
    this->pass_balls[i] = pass_balls[i];
    this->full_balls[i] = full_balls[i];
  }
}

// Конструктор с параметрами
RecordBook::RecordBook(char initials[][str_len], char subject_names[][str_len], char dates[][str_len], size_t pass_balls[], float full_balls[]) {
  for (size_t i = 0; i < sub_date_len; i++) {
    strcpy(this->subject_names[i], subject_names[i]);
    strcpy(this->dates[i],  dates[i]);
  }
  for (size_t i = 0; i < ball_init_len; i++) {
    strcpy(this->initials[i], initials[i]);
    this->pass_balls[i] = pass_balls[i];
    this->full_balls[i] = full_balls[i];
  }
}

/* ------------------------------------------------------------ МЕТОДЫ ------------------------------------------------------------ */

// Получение массива инициалов
vector<char*> RecordBook::get_initials() {
  vector <char*> temp_list;
  
  for (auto initial : initials) {
    temp_list.push_back(initial);
  }
  
  return temp_list;
}

// Вывод имеющихся данных
void RecordBook::get_full_info() {
  cout << "Student initials: ";
  for (size_t i = 0; i < ball_init_len; i++) {
    cout << initials[i] << ' ';
  }
  cout << endl;

  for (size_t i = 0; i < sub_date_len; i++) {
    cout << i+1 << " Date: " << dates[i] << '\t' << " Subject: " << subject_names[i] << endl;
  }

  cout << "Pass Balls: ";
  for (size_t i = 0; i < ball_init_len; i++) {
    cout << pass_balls[i] << ' ';
  }
  cout << "\nFull Balls: ";
  for (size_t i = 0; i < ball_init_len; i++) {
    cout << full_balls[i] << ' ';
  }
  cout << endl << endl;
}

// Метод изменения - принимает заранее введенный параметр, на который надо изменить
void RecordBook::change_information_string(char info_to_change[str_len]) {
  size_t choice;
  cout << "What do you want to change?\n1)Initials\n2)Subject Names\n3)Dates\n4)Pass Balls\n5)Full Balls\nYour choice: "; cin >> choice;

  switch (choice) {
    case 1: {  // Посимвольное изменение данных о ФИО
      size_t choice;
      cout << "1)Surname 2)Name 3)Lastname\nYour choice: "; cin >> choice;

      for (size_t i = 0; i < str_len; i++) {
        initials[choice - 1][i] = info_to_change[i];
      }
      break;
    }
    case 2: {  // Посимвольное изменение данных о предметах
      size_t choice;
      cout << "Number of subject to change: "; cin >> choice;

      for (size_t i = 0; i < str_len; i++) {
        subject_names[choice - 1][i] = info_to_change[i];
      }
      break;
    }  
    case 3: {  // Посимвольное изменение данных о датах
      size_t choice;
      cout << "Number of date to change: "; cin >> choice;

      for (size_t i = 0; i < str_len; i++) {
        dates[choice - 1][i] = info_to_change[i];
      }
      break;
    }
      
  }
}

// Изменение численных данных
void RecordBook::change_information_digits(size_t info_to_change) {
  size_t choice;
  cout << "What do you want to change?\n1)Full Balls\n2)Pass Balls\nYour choice: "; cin >> choice;

  if (choice == 1) {
    size_t choice;
    cout << "Number of balls to change: "; cin >> choice;
    full_balls[choice - 1] = info_to_change;
  }

  if (choice == 2) {
    size_t choice;
    cout << "Number of balls to change: "; cin >> choice;
    pass_balls[choice - 1] = info_to_change;
  }
}

// Почленное сохранение объекта класса в бинарный файл
void RecordBook::save_binary(string path) {
  ofstream file;  // Объект file класса ofstream

  file.open(path.c_str(), ios::binary);  // Открываем файл по пути path, в противном случае создадим новый

  file.write((char*)&initials, sizeof(initials));
  file.write((char*)&subject_names, sizeof(subject_names));
  file.write((char*)&dates, sizeof(dates));
  file.write((char*)&pass_balls, sizeof(pass_balls));
  file.write((char*)&full_balls, sizeof(full_balls));

  file.close();
  cout << "Saved Successful!" << endl;
}

// Почленное считывание данных: вернет объект с прочитанными из файла данными
RecordBook RecordBook::read_binary(string path) {
  ifstream file;
  RecordBook object;  // Пустой объект для записи в НЕГО из файла

  file.open(path.c_str(), ios::out | ios::binary);

  file.read((char*)&object.initials, sizeof(initials));
  file.read((char*)&object.subject_names, sizeof(subject_names));
  file.read((char*)&object.dates, sizeof(dates));
  file.read((char*)&object.pass_balls, sizeof(pass_balls));
  file.read((char*)&object.full_balls, sizeof(full_balls));

  file.close();
  cout << "Read Successful!" << endl;
  return object;  // Вернет считанный объект
}
