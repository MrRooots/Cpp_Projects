#include <iostream>
#include <fstream>
using namespace std;

void printer(ifstream &f){
	int x;

	if (f >> x) {
    if (x > 0) {cout << x << ' ';}

    printer(f);

    if (x < 0) {cout << x << ' ';}
  }
}

void my_func(){
	int x;

	if (cin >> x) {
		if (x > 0) {
			cout << x << endl;
		}

		my_func();

		if(x < 0) {
			cout << x << endl;
		}
	}
}

int main() {
	// ifstream f ("d:\\file.txt");
	//
	// if (!f.is_open()) {  // Если файл не удалось открыть
  //   cout << "Failed!";
  //   return 0;
  // } else {
  //   cout << "Result is: ";
  //   printer(f);
  //   f.close();
  // }

	my_func();

  return 0;
}
