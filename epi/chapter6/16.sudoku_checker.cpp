#include <bits/stdc++.h>
using namespace std;

bool checker(const int rStart, const int rEnd, const int cStart, const int cEnd, const vector<vector<int>> &table) {

  vector<bool> tmp(table.size()+1,false);
  for (int i=rStart; i<=rEnd; ++i) {
    for (int j=cStart; j<=cEnd; ++j) {
      if (table[i][j]) {
	if (tmp[table[i][j]]) return false;
	else tmp[table[i][j]] = true;
      }
    }
  }
  return true;
}

bool sudokuChecker(const vector<vector<int>> &table) {

  // check every row
  for (int i=0; i<table.size(); ++i) {
    if (!checker(i,i,0,table[i].size()-1,table)) return false;
  }

  // check every column
  for (int j=0; j<table[0].size(); ++j) {
    if (!checker(0,table.size()-1,j,j,table)) return false;
  }

  // check every square
  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      if (!checker(3*i, 3*i+2, 3*j, 3*j+2, table)) return false;
    }
  }

  // every check passed
  return true;
  
}

int main(int argc, char *argv[]) {
  vector<vector<int>> table = {{5,3,0,0,7,0,0,0,0},
                               {6,0,0,1,9,5,0,0,0},
                               {0,9,8,0,0,0,0,6,0},
                               {8,0,0,0,6,0,0,0,3},
                               {4,0,0,8,0,3,0,0,1},
                               {7,0,0,0,2,0,0,0,6},
                               {0,6,0,0,0,0,2,8,0},
                               {0,0,0,4,1,9,0,0,5},
                               {0,0,0,0,8,0,0,7,9}};

  cout << sudokuChecker(table) << endl;
  return 0;
}
