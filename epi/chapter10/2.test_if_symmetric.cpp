#include <bits/stdc++.h>
#include "binaryTree.hpp"
using namespace std;

template <typename T>
bool isSymmetricHelper(const unique_ptr<binaryTreeNode<T>> &left, const unique_ptr<binaryTreeNode<T>> &right) {
  if (!left) return !right;
  if (!right) return !left;
  if (left->value != right->value) return false;
  return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

template <typename T>
bool isSymmetric(const unique_ptr<binaryTreeNode<T>> &root) {
  if (!root) return true;
  return isSymmetricHelper(root->left, root->right);
}

int main(int argc, char *argv[]) {
  return 0;
}
