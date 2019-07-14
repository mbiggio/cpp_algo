#include<bits/stdc++.h>
using namespace std;

typedef enum {WHITE, BLACK} Color;
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

ostream &operator<<(ostream &os, const Coordinate &c) {
  os << "{ " << c.x << "," << c.y << " }";
  return os;
}

bool searchMazeHelper(vector<vector<Color>> &maze, const Coordinate &start, const Coordinate &end, vector<Coordinate> &result) {

  static const vector<Coordinate> kDirections = {
    Coordinate{0,1}, Coordinate{0,-1}, Coordinate{1,0}, Coordinate{-1,0}
  };

  auto isValid = [&](const Coordinate &point){
    return point.x >= 0 &&
           point.x < maze.size() &&
	   point.y >= 0 &&
	   point.y < maze[0].size();
  };

  maze[start.x][start.y] = BLACK;
  result.push_back(start);
  if (start == end) return true;

  for (int i=0; i<kDirections.size(); ++i) {
    Coordinate p = start + kDirections[i];
    if (isValid(p) && maze[p.x][p.y] == WHITE) {
      if (searchMazeHelper(maze,p,end,result)) return true;
    }
  }
  result.pop_back();
  return false;
}

vector<Coordinate> searchMaze(vector<vector<Color>> &maze, const Coordinate &start, const Coordinate &end) {
  vector<Coordinate> result;
  searchMazeHelper(maze,start,end,result);
  return result;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{ ";
  for (const T &el : v) {
    os << el << ' ';
  }
  os << "} ";
  return os;
}

int main(int argc, char *argv[]) {
  vector<vector<Color>> maze = {
    {BLACK, WHITE, WHITE, WHITE, WHITE, WHITE, BLACK, BLACK, WHITE, WHITE},
    {WHITE, WHITE, BLACK, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
    {BLACK, WHITE, BLACK, WHITE, WHITE, BLACK, BLACK, WHITE, BLACK, BLACK},
    {WHITE, WHITE, WHITE, BLACK, BLACK, BLACK, WHITE, WHITE, BLACK, WHITE},
    {WHITE, BLACK, BLACK, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
    {WHITE, BLACK, BLACK, WHITE, WHITE, BLACK, WHITE, BLACK, BLACK, WHITE},
    {WHITE, WHITE, WHITE, WHITE, BLACK, WHITE, WHITE, WHITE, WHITE, WHITE},
    {BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, WHITE, WHITE},
    {BLACK, WHITE, BLACK, BLACK, WHITE, WHITE, WHITE, BLACK, BLACK, BLACK},
    {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLACK, BLACK, WHITE}
  };

  vector<Coordinate> result = searchMaze(maze, 
                                         Coordinate{static_cast<int>(maze.size())-1,0}, 
					 Coordinate{0,static_cast<int>(maze[0].size())-1});

  cout << result << '\n';
  return 0;
}
