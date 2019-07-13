#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

template <typename T>
void deleteNode(shared_ptr<node<T>> n) {
  if (!n->next) throw invalid_argument("node to delete cannot be the last");
  n->value = n->next->value;
  n->next = n->next->next;
}

int main(int argc, char *argv[]) {
  shared_ptr<node<int>> n1,n2,n3,n4,n5,n6;

  n1 = make_shared<node<int>>(1);
  n2 = make_shared<node<int>>(2);
  n3 = make_shared<node<int>>(3);
  n4 = make_shared<node<int>>(4);
  n5 = make_shared<node<int>>(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  deleteNode(n3);
  while (n1) {
    cout << n1->value << ' ';
    n1 = n1->next;
  }
  cout << '\n';

  return 0;
}
