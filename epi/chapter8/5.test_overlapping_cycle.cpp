#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

template <typename T>
int getLength(shared_ptr<node<T>> h_start,
              shared_ptr<node<T>> h_end) {
  int l=0;
  while (h_start != h_end) {
    h_start = h_start->next;
    ++l;
  }
  return l;
}

template <typename T>
shared_ptr<node<T>> getCommonNodeNoCycle(shared_ptr<node<T>> h1_start,
                                         shared_ptr<node<T>> h1_end,
                                         shared_ptr<node<T>> h2_start,
		                 	 shared_ptr<node<T>> h2_end) {

  int l1 = getLength(h1_start, h1_end), l2 = getLength(h2_start, h2_end);
  while (l1 > l2) {
    h1_start = h1_start->next;
    --l1;
  }
  while (l2 > l1) {
    h2_start = h2_start->next;
    --l2;
  }

  while (h1_start != h1_end && h2_start != h2_end) {
    if (h1_start == h2_start) return h1_start;
    h1_start = h1_start->next; h2_start = h2_start->next;
  }
  return nullptr;
}

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

template <typename T>
shared_ptr<node<T>> getCommonNode(shared_ptr<node<T>> h1, shared_ptr<node<T>> h2) {
  shared_ptr<node<T>> n1 = getCycleStart(h1), n2 = getCycleStart(h2);
  if ((n1 && !n2) || (!n1 && n2)) return nullptr;
  if (!n1 && !n2) return getCommonNodeNoCycle(h1,n1,h2,n2);

  shared_ptr<node<T>> n;
  // both of them end up in a cycle
  // 1\ check if the common node is before the cycle
  n = getCommonNodeNoCycle(h1,n1,h2,n2);
  if (n) return n;

  // 2\ check if the common node is in the cycle
  if (n1 == n2) return n1;
  n = n1->next;
  while (n != n1 && n != n2) n = n->next;
  return n==n1?nullptr:n1;
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

  n5->next = n1;
  common = getCommonNode(n1,n6);
  cout << (common?to_string(common->value):"NULL") << '\n';

  return 0;
}
