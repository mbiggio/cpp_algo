#include <bits/stdc++.h>
using namespace std;

using Color = enum {WHITE, BLACK, GREY};
struct Coordinate {
  bool operator==(const Coordinate &other) const {
    return x == other.x && y == other.y;
  }

  Coordinate operator+(const Coordinate &other) const {
    return Coordinate{this->x + other.x, this->y + other.y};
  }

  friend ostream &operator<<(ostream &os, const Coordinate &c);

  int x;
  int y;
};


void flipColor(vector<vector<Color>> &matrix, const Coordinate &start) {

  static const vector<Coordinate> kDirections = {
    Coordinate{0,1}, Coordinate{0,-1}, Coordinate{1,0}, Coordinate{-1,0}
  };

  auto isValid = [&](const Coordinate &point){
    return point.x >= 0 &&
           point.x < matrix.size() &&
	   point.y >= 0 &&
	   point.y < matrix[0].size();
  };

  matrix[start.x][start.y] = GREY;
  for (int i=0; i<kDirections.size(); ++i) {
    Coordinate p = start + kDirections[i];
    if (isValid(p) && matrix[p.x][p.y] == WHITE) {
      flipColor(matrix, p);
    }
  }
}

ostream &operator<<(ostream &os, const vector<vector<Color>> &matrix) {
  for (int i=0; i<matrix.size(); ++i) {
    for (int j=0; j<matrix[i].size(); ++j) {
      os << (matrix[i][j]==BLACK?1:0) << ' ';
    }
    cout << '\n';
  }
  return os;
}

void fillSurroundedRegions(vector<vector<Color>> &matrix) {
  for (int i=0; i<matrix.size(); ++i) {
    if (matrix[i][0] == WHITE) flipColor(matrix, Coordinate{i,0});
    if (matrix[i][matrix[i].size()-1] == WHITE) flipColor(matrix, Coordinate{i,(int)matrix[i].size()-1});
  }

  for (int j=0; j<matrix[0].size(); ++j) {
    if (matrix[0][j] == WHITE) flipColor(matrix, Coordinate{0,j});
    if (matrix[matrix.size()-1][j] == WHITE) flipColor(matrix, Coordinate{(int)matrix.size()-1,j});
  }

  for (int i=0; i<matrix.size(); ++i) {
    for (int j=0; j<matrix[i].size(); ++j) {
      if (matrix[i][j] == GREY) matrix[i][j] = WHITE;
      else if (matrix[i][j] == WHITE) matrix[i][j] = BLACK;
    }
  }
}

int main(int argc, char *argv[]) {
  vector<vector<Color>> matrix = {
    {BLACK, BLACK, BLACK, BLACK},
    {WHITE, BLACK, WHITE, BLACK},
    {BLACK, WHITE, WHITE, BLACK},
    {BLACK, BLACK, BLACK, BLACK}
  };

  fillSurroundedRegions(matrix);
  cout << matrix << '\n';

  return 0;
}
