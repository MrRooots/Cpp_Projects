// Программа влада

#include <iostream>
#include <fstream>
using namespace std;

class Worker {
public:
  Worker();                             // Конструктор по умолчанию
  Worker(size_t count);                 // Конструктор с параметрами
  void save_binary(char[], Worker);     // Сохранение
  void read_binary(char[], Worker&);    // Чтение
  void print();                         // Вывод

private:
  char bio[3][255];
  char date[6][255];
  char exam[6][255];
  char mark[6][3];
};

// Кострутор, который создаст заготовочный объект, в который будет записан файл, дабы проверить работоспособность
Worker::Worker() {
  // Заготовочные переменный
  char bioNew[3][255]{"Marek", "Nikita", "Dmitrievich"};
  char examNew[6][255]{
    "Mathematical Analysis", "Algebra and Geometry", "Basics of programming",
    "English Language", "Effecient Communication", "Physical Education"
  };
  char dateNew[6][255]{
    "01.01.2020", "02.01.2020", "03.01.2020",
    "04.01.2020", "05.01.2020", "06.01.2020"
  };
  char markNew[6][4]{"0", "1", "123", "3", "65", "90"};

  // Присвоим заготовочные переменные переменным класса (может ты сможешь придумать как сократить код)
  for (size_t i = 0; i < 3; i++) {
    for (size_t l = 0; l < 255; l++) {
      bio[i][l] = bioNew[i][l];
    }
  }
  for (size_t i = 0; i < 6; i++) {
    for (size_t l = 0; l < 255; l++) {
      exam[i][l] = examNew[i][l];
      date[i][l] = dateNew[i][l];
    }
  }
  for (size_t i = 0; i < 6; i++) {
    for (size_t l = 0; l < 4; l++) {
      mark[i][l] = markNew[i][l];
    }
    
  }
}

Worker::Worker(size_t count) {
  cout << "Enter a student initials: ";
  for (int i = 0; i < 3; i++) {
    cin >> bio[i];
  }
  for (size_t i = 0; i < count; i++){
    cout << "Enter an exam name, date and result: ";
    cin >> exam[i] >> date[i] >> mark[i];
  }
}

void Worker::save_binary(char path[], Worker object) {
  ofstream file;

  file.open(path, ios::in | ios::binary);
  file.write((char*)&object, sizeof(Worker));
  file.close();
  cout << "Saved!" << endl;
}

void Worker::read_binary(char path[], Worker& toSave) {
  ifstream file;
  Worker object;

  file.open(path, ios::out | ios::binary);
  file.read((char*)&object, sizeof(Worker));
  file.close();
  cout << "Read!" << endl;

  toSave = object;
}

void Worker::print() {
  cout << "Initials: ";
  for (size_t i = 0; i < 3; i++) {
    cout << bio[i] << ' ';
  }
  cout << endl;
  for (size_t i = 0; i < 6; i++) {
    cout << i+1 << ' ' << date[i] << '\t' << exam[i] << endl;
  }
}

int main() {
  // Worker oldstudent(6);
  Worker newstudent;
  newstudent.print();
  
  char path[] = "file.bin";
  newstudent.save_binary(path, newstudent);
  
  // oldstudent.save_binary(path, newstudent);
  // oldstudent.print();

  // newstudent.read_binary(path, newstudent);
  // newstudent.print();
  
}