#include <iostream>
#include <cstring>
using namespace std;

int main(){
  const char* a = "Nikita Marek";
  const char* b = "Nikita AMarek";

  int res = strcmp(a, b);
  cout << res;
}