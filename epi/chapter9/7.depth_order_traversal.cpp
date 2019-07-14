#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryTreeNode {
  BinaryTreeNode(const T &value) : value(value), left(nullptr), right(nullptr) {};
  T value;
  unique_ptr<BinaryTreeNode<T>> left;
  unique_ptr<BinaryTreeNode<T>> right;
};

/*
 * BFS with sentinel nodes
 * to mark the end of levels
 */
template <typename T>
vector<vector<T>> depthOrderTraversalWithSentinels(const unique_ptr<BinaryTreeNode<T>> &root) {  
  if (!root) return {};
  vector<vector<T>> result;
  queue<BinaryTreeNode<T>*> q;
  q.emplace(nullptr); q.emplace(root.get());

  while (q.size()!=1 || q.front()) {
    auto ptr = q.front();
    q.pop();
    if (ptr==nullptr) {
      result.push_back({});
      q.emplace(nullptr);
    }
    else {
      result.back().emplace_back(ptr->value);
      if (ptr->left) q.emplace(ptr->left.get());
      if (ptr->right) q.emplace(ptr->right.get());
    }
  }
  return result;
}

/*
 * BFS with sentinel nodes
 * to mark the end of levels
 */
template <typename T>
vector<vector<T>> depthOrderTraversal(const unique_ptr<BinaryTreeNode<T>> &root) {  
  if (!root) return {};
  vector<vector<T>> result;
  queue<BinaryTreeNode<T>*> curQueue, auxQueue;
  curQueue.emplace(root.get());
  int level = 0;

  while (!curQueue.empty()) {
    auto ptr = curQueue.front();
    curQueue.pop();
    if (level >= result.size()) result.push_back({});
    result[level].emplace_back(ptr->value);
    if (ptr->left) auxQueue.emplace(ptr->left.get());
    if (ptr->right) auxQueue.emplace(ptr->right.get());

    if (curQueue.empty()) {
      swap(curQueue,auxQueue);
      ++level;
    }
  }
  return result;
}

template <typename T>
vector<vector<T>> inverseDepthOrderTraversal(const unique_ptr<BinaryTreeNode<T>> &root) {
  if (!root) return {};
  vector<vector<T>> result;
  stack<BinaryTreeNode<T>*> curStack, auxStack;
  curStack.emplace(root.get());
  int level = 0;

  while (!curStack.empty()) {
    auto ptr = curStack.top();
    curStack.pop();
    if (level >= result.size()) result.push_back({});
    result[level].emplace_back(ptr->value);
    if (level%2) {      
      if (ptr->right) auxStack.emplace(ptr->right.get());
      if (ptr->left) auxStack.emplace(ptr->left.get());
    }
    else {
      if (ptr->left) auxStack.emplace(ptr->left.get());
      if (ptr->right) auxStack.emplace(ptr->right.get());
    }

    if (curStack.empty()) {
      swap(curStack,auxStack);
      ++level;
    }
  }
  return result;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
  for (const vector<T> &vv : v) {
    os << "{ ";
    for (const T &vvv : vv) {
      os << vvv << ' ';
    }
    os << "} ";
  }
  return os;
}

int main(int argc, char *argv[]) {
  {
    unique_ptr<BinaryTreeNode<int>> n1 = make_unique<BinaryTreeNode<int>>(1);
    unique_ptr<BinaryTreeNode<int>> n2 = make_unique<BinaryTreeNode<int>>(2);
    unique_ptr<BinaryTreeNode<int>> n3 = make_unique<BinaryTreeNode<int>>(3);
    unique_ptr<BinaryTreeNode<int>> n4 = make_unique<BinaryTreeNode<int>>(4);
    unique_ptr<BinaryTreeNode<int>> n5 = make_unique<BinaryTreeNode<int>>(5);
    unique_ptr<BinaryTreeNode<int>> n6 = make_unique<BinaryTreeNode<int>>(6);
    unique_ptr<BinaryTreeNode<int>> n7 = make_unique<BinaryTreeNode<int>>(7);

    n2->left = move(n4);
    n2->right = move(n5);
    n3->left = move(n6);
    n3->right = move(n7);
    n1->left = move(n2);
    n1->right = move(n3);

    cout << depthOrderTraversal(n1) << endl;
    cout << depthOrderTraversalWithSentinels(n1) << endl;
    cout << inverseDepthOrderTraversal(n1) << endl;
  }

  return 0;
}
