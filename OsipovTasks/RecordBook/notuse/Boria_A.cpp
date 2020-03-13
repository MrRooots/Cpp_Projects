#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T, typename A>
vector<T> func(A   &   a) {
  vector<T> arr;
  for (auto x: a) {
    arr.push_back(x);
  }
  return arr;
}

int main() {
  list<int> a{1,2,3,4};
  vector<int> b;
  b = func(a);
}


  // cout << clamp(56, 4, 90);
  // size_t arr[5]{1,2,3,4,5};
  // for (auto element : arr) {
  //   cout << element << ' ';
  // }