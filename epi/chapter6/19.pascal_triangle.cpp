#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangle(const int n) {
  if (n==0) return {};
  vector<vector<int>> result(n);
  result[0].push_back(1);
  for (int i=1; i<n; ++i) {
    result[i].push_back(1);
    for (int j=1; j<i; ++j) result[i].push_back(result[i-1][j]+result[i-1][j-1]);
    result[i].push_back(1);
  }
  return result;
}


ostream &operator<<(ostream &os, const vector<vector<int>> &table) {
  for (const vector<int> &row : table) {
    os << '{';
    for (const int val : row) {
      os << val << ' ';
    }
    os << "} ";
  }
  return os;
}



int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  cout << pascalTriangle(n) << endl;
  return 0;
}
