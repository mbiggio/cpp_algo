#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct binaryTreeNode {
  T value;
  unique_ptr<binaryTreeNode<T>> left, right;
};
