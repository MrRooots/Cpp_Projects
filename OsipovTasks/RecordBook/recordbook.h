#include <fstream>   // Запись в файл
#include <iostream>
using namespace std;

typedef char LIST_TYPO[3][255];  // Пользовательски тип, для возврата из функции - массив инициалов

class RecordBook {
public:
  RecordBook();                                                             // Конструктор по умолчанию
  RecordBook(char[][255], char[][255], char[][255], size_t[], float[]);     // Конструктор с параметрами
  LIST_TYPO* get_initials();                                                // Возврат пользовательского типа - массива инициалов
  void get_full_info();                                                     // Вывод всей информации о студенте
  void save_binary(string, RecordBook);                                     // Сохранение в файл
  RecordBook read_binary(string, RecordBook &);                             // Чтение из файла
  void change_information_string(char[255]);                                // Изменение строковых данных
  void change_information_digits(size_t);                                   //  Изменение числовой инф-ии
  void operator=(const RecordBook& object) {                                // Перегрузка опретаора "="
    for (size_t i = 0; i < 3; i++) {
      for (size_t l = 0; l < 255; l++) {
        this->initials[i][l] = object.initials[i][l];
      }
      this->pass_balls[i] = object.pass_balls[i];
      this->full_balls[i] = object.full_balls[i];
    }
    for (size_t i = 0; i < 6; i++) {
      for (size_t l = 0; l < 255; l++) {
        this->subject_names[i][l] = object.subject_names[i][l];
        this->dates[i][l] = object.dates[i][l];
      }
    }
  }

private:
  char initials[3][255];        // Инициалы
  char subject_names[6][255];   // Названия предметов
  char dates[6][255];           // Даты
  size_t pass_balls[3];         // Зачетные баллы
  float full_balls[3];          // Числовые баллы
};

// Конструктор по умолчанию
RecordBook::RecordBook() {
  // Инициалы
  char initials[3][255] = {"Invanov", "Ivan", "Ivanovich"};
  for (size_t i = 0; i < 3; i++) {
    for (size_t l = 0; l < 255; l++) {
      this->initials[i][l] = initials[i][l];
    }
  }

  // Предметы
  char subject_names[6][255] = {
    "Mathematical Analysis", "Algebra and Geometry", "Basics of programming",
    "English Language", "Effecient Communication", "Physical Education"};
  for (size_t i = 0; i < 6; i++) {
    for (size_t l = 0; l < 255; l++) {
      this->subject_names[i][l] = subject_names[i][l];
    }
  }

  // Даты
  char dates[6][255] = {
    "01.01.2020", "02.01.2020", "03.01.2020",
    "04.01.2020", "05.01.2020", "06.01.2020"};
  for (size_t i = 0; i < 6; i++) {
    for (size_t l = 0; l < 255; l++) {
      this->dates[i][l] = dates[i][l];
    }
  }

  // Баллы
  size_t pass_balls[3]={0, 0, 0}; for (size_t i = 0; i < 3; i++) {this->pass_balls[i] = pass_balls[i];}
  float full_balls[3]={0, 0, 0}; for (size_t i = 0; i < 3; i++) {this->full_balls[i] = full_balls[i];}
}

// Конструктор с параметрами
RecordBook::RecordBook(char initials[][255], char subject_names[][255], char dates[][255], size_t pass_balls[], float full_balls[]) {
  for (size_t i = 0; i < 3; i++) {
    for (size_t l = 0; l < 255; l++) {
      this->initials[i][l] = initials[i][l];
    }
  }
  for (size_t i = 0; i < 6; i++) {
    for (size_t l = 0; l < 255; l++) {
      this->subject_names[i][l] = subject_names[i][l];
    }
  }
  for (size_t i = 0; i < 6; i++) {
    for (size_t l = 0; l < 255; l++) {
      this->dates[i][l] = dates[i][l];
    }
  }
  for (size_t i = 0; i < 3; i++) {
    this->pass_balls[i] = pass_balls[i];
  }
  for (size_t i = 0; i < 3; i++) {
    this->full_balls[i] = full_balls[i];
  }
}

// Получение массива инициалов
LIST_TYPO* RecordBook::get_initials() {
  static LIST_TYPO list{"", "", ""};
  for (size_t i = 0; i < 3; i++) {
    for (size_t l = 0; l < 255; l++) {
      list[i][l] = initials[i][l];
    }
  }
  return &initials;
}

// Вывод имеющихся данных
void RecordBook::get_full_info() {
  cout << "Student initials: ";
  for (size_t i = 0; i < 3; i++) {
    cout << initials[i] << ' ';
  }
  cout << endl;

  for (size_t i = 0; i < 6; i++) {
    cout << i+1 << " Date: " << dates[i] << '\t' << " Subject: " << subject_names[i] << endl;
  }

  cout << "Pass Balls: ";
  for (size_t i = 0; i < 3; i++) {
    cout << pass_balls[i] << ' ';
  }
  cout << "\nFull Balls: ";
  for (size_t i = 0; i < 3; i++) {
    cout << full_balls[i] << ' ';
  }
  cout << endl << endl;
}

// Метод изменения - принимает заранее введенный параметр, на который надо изменить
void RecordBook::change_information_string(char info_to_change[255]) {
  size_t choice;
  cout << "What do you want to change?\n1)Initials\n2)Subject Names\n3)Dates\n4)Pass Balls\n5)Full Balls\nYour choice: "; cin >> choice;

  switch (choice) {
    case 1: {  // Посимвольное изменение данных о ФИО
      size_t choice;
      cout << "1)Surname 2)Name 3)Lastname\nYour choice: "; cin >> choice;

      for (size_t i = 0; i < 255; i++) {
        initials[choice - 1][i] = info_to_change[i];
      }
      break;
    }
    case 2: {  // Посимвольное изменение данных о предметах
      size_t choice;
      cout << "Number of subject to change: "; cin >> choice;

      for (size_t i = 0; i < 255; i++) {
        subject_names[choice - 1][i] = info_to_change[i];
      }
      break;
    }  
    case 3: {  // Посимвольное изменение данных о датах
      size_t choice;
      cout << "Number of date to change: "; cin >> choice;

      for (size_t i = 0; i < 255; i++) {
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
void RecordBook::save_binary(string path, RecordBook object) {
  ofstream file;  // Объект file класса ofstream

  file.open(path.c_str(), ios::in | ios::binary);  // Открываем файл по пути path, в противном случае создадим новый

  file.write((char*)&initials, sizeof(initials));
  file.write((char*)&subject_names, sizeof(subject_names));
  file.write((char*)&dates, sizeof(dates));
  file.write((char*)&pass_balls, sizeof(pass_balls));
  file.write((char*)&full_balls, sizeof(full_balls));

  file.close();
  cout << "Saved Successful!" << endl;
}

// Почленное считывание данных: вернет объект с прочитанными из файла данными
RecordBook RecordBook::read_binary(string path, RecordBook &my_record) {
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
