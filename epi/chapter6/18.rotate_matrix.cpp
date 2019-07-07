#include <bits/stdc++.h>
using namespace std;

void rotateLayer(const int start, const int end, vector<vector<int>> &table) {
  for (int offset = 0; offset < end-start-1; ++offset) {
    int tmp = table[start][start+offset];
    swap(tmp, table[start+offset][end-1]);
    swap(tmp, table[end-1][end-1-offset]);
    swap(tmp, table[end-1-offset][start]);
    swap(tmp, table[start][start+offset]);
  }
}

void rotateMatrix(vector<vector<int>> &table) {
  for (int layer=0; layer<table.size()/2; ++layer) {
    rotateLayer(layer, table.size()-layer, table);
  }
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
  {
    vector<vector<int>> table = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotateMatrix(table);
    cout << table << endl;
  }
  {
    vector<vector<int>> table = {{1,2,3},{4,5,6},{7,8,9}};
    rotateMatrix(table);
    cout << table << endl;
  }
  return 0;
}
