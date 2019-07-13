#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct node {
  node(const T &value) : value(value), next(nullptr) {};
  T value;
  shared_ptr<node<T>> next;
};

template <typename T>
class listBuilder {
private:
  shared_ptr<node<T>> head, tail;
public:
  listBuilder() : head(nullptr), tail(nullptr) {};

  listBuilder &append(listBuilder &&other) {
    if (other.empty()) return *this;
    if (empty()) {
      head = other.head;
      tail = other.tail;
      return *this;
    }
    tail->next = other.head;
    tail = other.tail;
    return *this;
  }

  shared_ptr<node<T>> getHead() const {
    return head;
  }

  shared_ptr<node<T>> push_back(const T &value) {
    shared_ptr<node<T>> n = make_shared<node<T>>(value);
    return push_back(n);
  }

  shared_ptr<node<T>> push_front(const T &value) {
    shared_ptr<node<T>> n = make_shared<node<T>>(value);
    return push_front(n);
  }

  shared_ptr<node<T>> push_front(shared_ptr<node<T>> n) {
    shared_ptr<node<T>> tmp = n->next;
    if (empty()) {
      n->next = nullptr;
      head = tail = n;
    }
    else {
      n->next = head;
      head = n;
    }
    return tmp;
  }

  shared_ptr<node<T>> push_back(shared_ptr<node<T>> n) {
    shared_ptr<node<T>> tmp = n->next;
    n->next = nullptr;
    if (empty()) {
      head = tail = n;
    }
    else {
      tail->next = n;
      tail = n;
    }
    return tmp;
  }

  bool empty() const {
    return head == nullptr;
  }
};

