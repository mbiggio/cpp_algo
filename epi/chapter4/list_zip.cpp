#include <bits/stdc++.h>
using namespace std;

struct node {
  node(int val) : val(val) {}
  int val;
  node *next = nullptr;
};



void print(node *head) {
  while(head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}



node *get_middle_element(node *head) {
  node *start = head, *end = head->next;
  while (end && end->next) {
    start = start->next;
    end = end->next->next;
  }
  return start;
}



node *reverse(node *head) {
  if (!head->next) return head;
  node *newHead = reverse(head->next);
  head->next->next = head;
  head->next = nullptr;
  return newHead;
}



node *list_zip(node *head) {
  if (!head || !head->next) return head;
  node *middle = get_middle_element(head);
  node *upperHalf = reverse(middle->next);
  middle->next = nullptr;
  node *lowerHalf = head->next;

  node *curNode = head;
  bool takeUpperHalf = true;
  while (lowerHalf || upperHalf) {
    node **sublist = takeUpperHalf?&upperHalf:&lowerHalf;
    curNode->next = (*sublist);
    (*sublist) = (*sublist)->next;
    curNode = curNode->next;
    takeUpperHalf = !takeUpperHalf;
  }

  return head;
}

int main(int argc, char *argv[]) {
  node *n1 = new node{1};
  node *n2 = new node{2};
  node *n3 = new node{3};
  node *n4 = new node{4};
  node *n5 = new node{5};
  node *n6 = new node{6};

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;

  print(list_zip(n1));
  return 0;
}
