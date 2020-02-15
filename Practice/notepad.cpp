#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main() {
  string line;
  cin >> line;
  const char* line_1 = line.c_str();
  cout << line_1 << ' ' << type_info::name() << '\n';

  return 0;
}
