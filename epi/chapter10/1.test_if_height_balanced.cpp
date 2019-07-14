#include <bits/stdc++.h>
#include "binaryTree.hpp"
using namespace std;


template <typename T>
pair<bool,int> isHeightBalancedHelper(const unique_ptr<binaryTreeNode<T>> &root) {
  if (!root) return {true,-1};
  int hl = -1, hr = -1;

  auto pl = isHeightBalancedHelper(root->left);
  if (!pl.first) return {false,0};
  hl=pl.second;

  auto pr = isHeightBalancedHelper(root->right);
  if (!pr.first) return {false,0};
  hr=pr.second;

  return {abs(hl-hr) <= 1, 1+max(hl,hr)};
}

template <typename T>
bool isHeightBalanced(const unique_ptr<binaryTreeNode<T>> &root) {
  return isHeightBalancedHelper(root).first;
}

int main(int argc, char *argv[]) {
  return 0;
}
