#include <iostream>
#include <vector>
using namespace std;

// Абстрактный класс предмет
class Subject {
public:
  Subject(vector<const char*> subject_list) {
    for (auto subject : subject_list) {
      subject_names.push_back(subject);
    }
  }
private:
  vector<const char*> subject_names;
};

// Наследники предмета - зачет и экзамен
class Test : Subject {
public:
private:
  vector<const char*> test_subjects;
};

class Exam : Subject {
public:

private:
  vector<const char*> exam_subjects;
};

int main() {
  vector<const char*> a {"nikita", "marek", "alpha"};
  vector<const char*> b {"nikita", "alpha"};
  cout << sizeof(a) << ' ' << sizeof(b) << endl;
  return 0;
}