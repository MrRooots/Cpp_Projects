#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const char *path = "D:\\file.txt";

class RecordBook {
private:
  string firstname, lastname, patronymic;
  string first_exam, second_exam, third_exam;
  string first_date, second_date, third_date;
  double first_ball, second_ball, third_ball;
public:
  // Прототипы
  RecordBook(string a="", string b, string c, string first_date, string second_date, string third_date, double first_ball, double second_ball, double third_ball);  // Конструктор
  void get_full_info();  // Получение полной информации (имя, даты, баллы)
  void save_to_file();  // Сохранение в файл объекта класса
  bool write(ostream& os);
};

// Конструктор
RecordBook::RecordBook(string a="", string b="", string c="", string first_date="", string second_date="", string third_date="", double first_ball=0, double second_ball=0, double third_ball=0) {
  this->firstname = a;
  this->lastname = b;
  this->patronymic = c;

  this->first_date = first_date;
  this->second_date = second_date;
  this->third_date = third_date;

  this->first_exam = "Mathematical analysis";
  this->second_exam = "Programming basics";
  this->third_exam = "Algebra and geometry";

  this->first_ball = first_ball;
  this->second_ball = second_ball;
  this->third_ball = third_ball;
}

void RecordBook::get_full_info() {
  cout << "------INFO------\n" << "Firstname: " << this->firstname << "\nLastname: " << this->lastname << "\nPatronymic: " << this->patronymic << endl;
  cout << "------BALL------\n" << first_date << " --> Mathematical analysis: " << first_ball << endl << second_date << " --> Programming basics: " << second_ball << endl << third_date << " --> Algebra and geometry: " << third_ball << endl;
}

bool RecordBook::write(ostream& os) {
  os.write((char *)this, sizeof(RecordBook));
  return os.good();
}

void RecordBook::save_to_file() {
  ofstream stream(path, ios::binary | ios::out);

  if (stream) {
    this->write(stream);
    cout << "\nSaved Successful!" << endl;
  } else {
    cout << "\nFile open error: " << path << endl;
  }
}

int main() {
  // Можно организовать ввод
  string a = "Marek", b = "Nikita", c = "Dmitrievich", g = "01.04.20", h = "21.01.20", i = "01.01.20";
  double d = 1.25, e = 15.4, f = 65.4;

  RecordBook MyRecord(a, b, c, g, h, i, d, e, f);

  // MyRecord.get_full_name();
  // MyRecord.get_current_ball();
  MyRecord.get_full_info();
  MyRecord.save_to_file();

  RecordBook NewRecod();
  NewRecod.get_full_info();

  return 0;
}
