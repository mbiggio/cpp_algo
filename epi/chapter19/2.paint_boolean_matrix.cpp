#include <bits/stdc++.h>
using namespace std;

using Color = enum {WHITE, BLACK};

void flip(Color &c) {
  c=(c==WHITE)?BLACK:WHITE;
}

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

  Color cur = matrix[start.x][start.y];
  flip(matrix[start.x][start.y]);
  for (int i=0; i<kDirections.size(); ++i) {
    Coordinate p = start + kDirections[i];
    if (isValid(p) && matrix[p.x][p.y] == cur) {
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

int main(int argc, char *argv[]) {
  vector<vector<Color>> matrix = {
    {BLACK, WHITE, BLACK, WHITE, WHITE, WHITE, BLACK, BLACK, BLACK, BLACK},
    {WHITE, WHITE, BLACK, WHITE, WHITE, BLACK, WHITE, WHITE, BLACK, BLACK},
    {BLACK, BLACK, BLACK, WHITE, WHITE, BLACK, BLACK, WHITE, BLACK, BLACK},
    {WHITE, BLACK, WHITE, BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, WHITE},
    {BLACK, WHITE, BLACK, WHITE, WHITE, WHITE, WHITE, BLACK, WHITE, WHITE},
    {BLACK, WHITE, BLACK, WHITE, WHITE, BLACK, WHITE, BLACK, BLACK, BLACK},
    {WHITE, WHITE, WHITE, WHITE, BLACK, WHITE, BLACK, WHITE, WHITE, BLACK},
    {BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, WHITE, WHITE},
    {BLACK, WHITE, BLACK, BLACK, WHITE, WHITE, WHITE, BLACK, BLACK, BLACK},
    {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLACK, BLACK, WHITE}
  };

  flipColor(matrix, Coordinate{5,4});
  cout << matrix << '\n';

  return 0;
}
