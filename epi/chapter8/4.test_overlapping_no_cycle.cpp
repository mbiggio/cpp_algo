#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

template <typename T>
int getLength(shared_ptr<node<T>> h) {
  int l=0;
  while (h) {
    h = h->next;
    ++l;
  }
  return l;
}

template <typename T>
shared_ptr<node<int>> getCommonNode(shared_ptr<node<T>> h1, shared_ptr<node<T>> h2) {
  int l1 = getLength(h1), l2 = getLength(h2);
  while (l1 > l2) {
    h1 = h1->next;
    --l1;
  }
  while (l2 > l1) {
    h2 = h2->next;
    --l2;
  }

  while (h1 && h2) {
    if (h1 == h2) return h1;
    h1 = h1->next; h2 = h2->next;
  }
  return nullptr;
}

int main(int argc, char *argv[]) {
  shared_ptr<node<int>> n1,n2,n3,n4,n5,n6;

  n1 = make_shared<node<int>>(1);
  n2 = make_shared<node<int>>(2);
  n3 = make_shared<node<int>>(3);
  n4 = make_shared<node<int>>(4);
  n5 = make_shared<node<int>>(5);
  n6 = make_shared<node<int>>(6);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  shared_ptr<node<int>> common;

  common = getCommonNode(n1,n6);
  cout << (common?to_string(common->value):"NULL") << '\n';

  n6->next = n3;
  common = getCommonNode(n1,n6);
  cout << (common?to_string(common->value):"NULL") << '\n';
  return 0;
}
