#include <iostream>
#include <cstring>
using namespace std;

size_t get_length(char * line) {
  size_t i = 0;
  while (line[++i]){}
  return i;
}

// Указатели и строки
int main() {
  char *name = "Nikita";

  cout << get_length(name);

  return 0;
}