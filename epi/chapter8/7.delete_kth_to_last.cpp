#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

// k = 3
// 1 2 3 4 5 6 7 8
//         o x     o

shared_ptr<node<int>> removeKthToLast(shared_ptr<node<int>> head, int k) {
  if (k <= 0) throw invalid_argument("k must be > 0");
  shared_ptr<node<int>> dummy = make_shared<node<int>>(0);
  dummy->next = head;
  shared_ptr<node<int>> p1 = dummy, p2 = dummy;
  int d=0;
  while (p2 && d<k+1) {
    p2 = p2->next;
    ++d;
  }

  if (d<k+1) return nullptr;
  while(p2) {
    p1 = p1->next;
    p2 = p2->next;
  }

  p1->next = p1->next->next;
  return dummy->next;
}

void print(shared_ptr<node<int>> p) {
  while(p) {
    cout << p->value << ' ';
    p = p->next;
  }
  cout << '\n';
}

int main(int argc, char *argv[]) {
  {
    shared_ptr<node<int>> head = nullptr;
    shared_ptr<node<int>> newHead = removeKthToLast(head,1);
    print(newHead);
  }
  {
    shared_ptr<node<int>> head = make_shared<node<int>>(1);
    shared_ptr<node<int>> newHead = removeKthToLast(head,1);
    print(newHead);
  }
  {
    shared_ptr<node<int>> n1,n2,n3;
    n1 = make_shared<node<int>>(1);
    n2 = make_shared<node<int>>(2);
    n3 = make_shared<node<int>>(3);

    n1->next = n2;
    n2->next = n3;
    shared_ptr<node<int>> newHead = removeKthToLast(n1,3);
    print(newHead);
    newHead = removeKthToLast(newHead,1);
    print(newHead);
  }
  return 0;
}
