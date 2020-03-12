#include <iostream>
#include <cstring>
#include <cstring>
#include <list>

using namespace std;


int main(){
  list<size_t> list_0 {1,2,3,4,5};
  list<size_t> list_1 {5,4,3,2,1};
  auto iter_0 = list_0.begin(); auto iter_1 = list_1.begin();
  
  cout << "List 0: "; for (auto x : list_0) {cout << x << ' ';} cout << endl;
  // cout << "List 1: "; for (auto x : list_1) {cout << x << ' ';} cout << endl;
  size_t index; cin >> index;
  advance(iter_0, --index);
  // cout << *iter_0 << endl;
  list_0.erase(iter_0);
  cout << "List 0: "; for (auto x : list_0) {cout << x << ' ';} cout << endl;
  // cout << *iter << endl;
  // advance(iter, 6);
  // cout << *iter << endl;
}