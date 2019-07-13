#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

template <typename T>
shared_ptr<node<T>> getCycleStart(shared_ptr<node<T>> head) {
  if (!head || !head->next) return nullptr;
  shared_ptr<node<T>> slow = head->next, fast = head->next->next;
  while (slow != fast && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  if (!fast || !fast->next) return nullptr;

  // determine cycle length;
  int length = 0;
  shared_ptr<node<T>> n = fast->next;
  while (n != fast) {
    n = n->next;
    ++length;
  }

  // determine cycle start
  shared_ptr<node<T>> n1 = head, n2 = head->next;
  for (int i=0; i<length; ++i) n2 = n2->next;

  while (n1 != n2) {
    n1 = n1->next; n2 = n2->next;
  }

  return n1;
}

int main(int argc, char *argv[]) {
  shared_ptr<node<int>> n1 = make_shared<node<int>>(1);
  shared_ptr<node<int>> n2 = make_shared<node<int>>(2);
  shared_ptr<node<int>> n3 = make_shared<node<int>>(3);
  shared_ptr<node<int>> n4 = make_shared<node<int>>(4);
  shared_ptr<node<int>> n5 = make_shared<node<int>>(5);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  shared_ptr<node<int>> c;

  c = getCycleStart(n1);
  cout << "cycle? " << (c?to_string(c->value):"NULL") << '\n';

  n5->next = n3;
  c = getCycleStart(n1);
  cout << "cycle? " << (c?to_string(c->value):"NULL") << '\n';
  return 0;
}
