#include <iostream>
using namespace std;

class Person{
public:                // Если ты принимаешь сдесь переменную с таким же именем как и в строке 14, то без стрелочек у тебя будет ошибка,
                                                                                // мол ты пытешься присвоить переменной name значение name
  void set_name(string name) {
    name = name;
  }
  void get_name() {
    cout << name << endl;
  }
private:
  string name = "";   // <- Вот это 14 строка
};


int main() {
  Person vlad;
  vlad.set_name("Vlad");
  vlad.get_name();


  return 0;
}
