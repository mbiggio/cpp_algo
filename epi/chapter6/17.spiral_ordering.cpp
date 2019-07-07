#include <bits/stdc++.h>
using namespace std;

void processLayer(const int start, const int end, const vector<vector<int>> &table, vector<int> &result) {
  if (end-start == 1) {
    result.push_back(table[start][start]);
    return;
  }

  for (int j=start; j<end-1; ++j) result.push_back(table[start][j]);
  for (int i=start; i<end-1; ++i) result.push_back(table[i][end-1]);
  for (int j=end-1; j>start; --j) result.push_back(table[end-1][j]);
  for (int i=end-1; i>start; --i) result.push_back(table[i][start]);

}

vector<int> spiralOrdering(const vector<vector<int>> &table) {
  int n = table.size();
  vector<int> result;
  for (int layer = 0; layer < ceil(n/2); ++layer) {
    processLayer(layer, n-layer, table, result);
  }
  return result;
}

ostream &operator<<(ostream &os, const vector<int> &v) {
  for (const int vv : v) os << vv << ' ';
  return os;
}

int main(int argc, char *argv[]) {
  cout << spiralOrdering({{1,2,3},{4,5,6},{7,8,9}}) << endl;
  cout << spiralOrdering({{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}) << endl;
  return 0;
}
