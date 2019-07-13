#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

shared_ptr<node<int>> merge(shared_ptr<node<int>> h1, 
                            shared_ptr<node<int>> h2) {

  listBuilder<int> builder;
  while (h1 && h2) {
    if (h1->value <= h2->value) h1 = builder.push_back(h1);
    else h2 = builder.push_back(h2);
  }

  while (h1) h1 = builder.push_back(h1);
  while (h2) h2 = builder.push_back(h2);

  return builder.getHead();
}

int main(int argc, char *argv[]) {
  shared_ptr<node<int>> l1,l2,l3;

  {
    listBuilder<int> lb;
    lb.push_back(2); lb.push_back(5); lb.push_back(7);
    l1 = lb.getHead();
  }
  {
    listBuilder<int> lb;
    lb.push_back(3); lb.push_back(11);
    l2 = lb.getHead();
  }

  l3 = merge(l1,l2);
  while (l3) {
    cout << l3->value << ' ';
    l3 = l3->next;
  }
  cout << '\n';
    
  return 0;
}
