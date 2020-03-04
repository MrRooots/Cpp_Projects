#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Worker {
public:
  Worker();  // По умолчанию
  Worker(char initialsCreate[6][255], char subject_namesCreate[6][255], char datesCreate[6][255], float full_ballsCreate  [6][3]);

  void get_exams();
  void save_binary(string, Worker);
  Worker read_binary(string);

private:
  char initials[3][255];        // Инициалы
  char subject_names[6][255];   // Названия предметов
  char dates[6][255];           // Даты
  char pass_balls[6][3];         // Зачетные баллы
};

// Создание пустой зачетки
Worker::Worker() {
  // Инициалы
  char initialsCreate[3][255]{"Invanov", "Ivan", "Ivanovich"};
  for (size_t i = 0; i < 3; i++) {
    for (size_t l = 0; l < 255; l++) {
      initials[i][l] = initialsCreate[i][l];
    }
  }

  // Предметы
  char subject_namesCreate[6][255]{
    "Mathematical Analysis", "Algebra and Geometry", "Basics of programming",
    "English Language", "Effecient Communication", "Physical Education"
  };
  for (size_t i = 0; i < 6; i++) {
    for (size_t l = 0; l < 255; l++) {
      subject_names[i][l] = subject_namesCreate[i][l];
    }
  }

  // Даты
  char datesCreate[6][255]{
    "01.01.2020", "02.01.2020", "03.01.2020",
    "04.01.2020", "05.01.2020", "06.01.2020"};
  for (size_t i = 0; i < 6; i++) {
    for (size_t l = 0; l < 255; l++) {
      dates[i][l] = datesCreate[i][l];
    }
  }

  // Баллы
  char pass_ballsCreate[6][3]{"1", "0", "0", "0", "0", "0"};
  for (size_t i = 0; i < 6; i++) {
    for (size_t l = 0; l < 3; l++) {
      pass_balls[i][l] = pass_ballsCreate[i][l];
    }
    
  }
  
}

// Конструктор с параметрами
Worker::Worker(char initialsCreate[3][255], char subject_namesCreate[6][255], char datesCreate[6][255], float full_ballsCreate[6][3]) {
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
  for (size_t i = 0; i < 6; i++) {
    for (size_t l = 0; l < 3; l++) {
      pass_balls[i][l] = pass_balls[i][l];
    }
    
  }
}

// Сохранение в бинарный файл
void Worker::save_binary(string path, Worker object) {
  ofstream file;

  file.open(path.c_str(), ios::in | ios::binary);
  file.write((char*)&object, sizeof(Worker));
  file.close();
}

// Чтение бинарного файла
Worker Worker::read_binary(string path) {
  ifstream file;
  Worker student;

  file.open(path.c_str(), ios::in | ios::binary);
  file.read((char*)&student, sizeof(Worker));
  file.close();

  return student;
}

// Печать имебщихся данных в красивой форме
void Worker::get_exams() {
  cout << "Student initials: ";
  for (size_t i = 0; i < 3; i++) {
    cout << initials[i] << ' ';
  }
  cout << endl;

  for (size_t i = 0; i < 6; i++) {
    cout << i+1 << " Date: " << dates[i] << '\t' << " Subject: " << subject_names[i] << endl;
  }

  cout << "Balls Balls: ";
  for (size_t i = 0; i < 6; i++) {
    cout << pass_balls[i] << ' ';
  }
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
  char pass_balls[6][3]{"1", "0", "1", "1", "0", "1"};

  Worker my_record;
  // my_record.get_exams();
  Worker new_record(initials_list, subject_names, dates_list, pass_balls);

  string path;
  cout << "Enter a path: ";
  cin >> path;

  my_record.save_binary(path, new_record);
  new_record = my_record.read_binary(path);
  new_record.get_exams();


}