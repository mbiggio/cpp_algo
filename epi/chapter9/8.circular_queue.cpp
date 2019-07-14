#include <bits/stdc++.h>
using namespace std;

template <typename T>
class circularQueue {
public:

  circularQueue() : buffer(getDefaultSize()), head(0), tail(0), elements(0) {};

  void enqueue(const T &element) {
    if (elements == buffer.size()) {
      rotate(buffer.begin(), buffer.begin()+head, buffer.end());
      head=0; tail=elements;
      buffer.resize(buffer.size()*getIncreaseFactor());
    }
    buffer[tail++] = element;
    tail %= buffer.size();
    ++elements;
  }

  T dequeue() {
    if (empty()) throw length_error("cannot dequeue from empty queue");
    T element = buffer[head++];
    head %= buffer.size();
    --elements;
    return element;
  }

  bool empty() const {
    return !elements;
  }

  int size() const {
    return elements;
  }

private:

  static const int getDefaultSize() {
    static const int kDefaultSize = 1;
    return kDefaultSize;
  }

  static const int getIncreaseFactor() {
    static const int kIncreaseFactor = 2;
    return kIncreaseFactor;
  }

  vector<T> buffer;
  int head;
  int tail;
  int elements;
};

int main(int argc, char *argv[]) {
  circularQueue<int> q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  cout << q.dequeue() << '\n';
  q.enqueue(4);
  cout << q.dequeue() << '\n';
  cout << q.dequeue() << '\n';
  q.enqueue(5);
  cout << q.dequeue() << '\n';
  cout << q.dequeue() << '\n';

  cout << q.empty() << '\n';
  return 0;
}
