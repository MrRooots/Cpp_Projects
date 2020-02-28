#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
using namespace std;

template<template<typename> class InContainer, typename T>
vector<T> resequence(const InContainer<T>& input) {
  vector<T> result;

  for (auto x : input) {
    result.push_back(x);
  }
  return result;
}


int main() {
  vector<size_t> v {1,2,3,4,5,6,7,8,9};
  resequence<deque>(v);

  // cout << typeid(result).name();

  return 0;
}
