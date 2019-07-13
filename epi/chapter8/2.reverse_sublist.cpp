#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

shared_ptr<node<int>> reverseSublist(shared_ptr<node<int>> head, int start, int end) {
  if (start >= end) return head;
  shared_ptr<node<int>> curNode = head;
  int curIdx = 1;

  listBuilder<int> lb1;
  while (curNode && curIdx < start) {
    curNode = lb1.push_back(curNode);
    ++curIdx;
  }

  listBuilder<int> lb2;
  while (curNode && curIdx <= end) {
    curNode = lb2.push_front(curNode);
    ++curIdx;
  }

  listBuilder<int> lb3;
  while (curNode) {
    curNode = lb3.push_front(curNode);
    ++curIdx;
  }

  lb1.append(move(lb2)).append(move(lb3));
  return lb1.getHead();
}

int main() {

  listBuilder<int> lb;
  lb.push_back(11); lb.push_back(3); lb.push_back(5); lb.push_back(7); lb.push_back(2);
  shared_ptr<node<int>> h = reverseSublist(lb.getHead(),2,4);

  while(h) {
    cout << h->value << ' ';
    h = h->next;
  }
  cout << '\n';
  return 0;
}
