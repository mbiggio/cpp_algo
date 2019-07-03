#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
  int x, y, width, height;
  friend ostream &operator<<(ostream &os, const Rectangle &r);
};

ostream &operator<<(ostream &os, const Rectangle &r) {
  os << "{" << r.x << "," << r.y << "," << r.width << "," << r.height << "}";
}

bool isIntersect(const Rectangle &r1, const Rectangle &r2) {
  return (r1.x <= r2.x + r2.width && r2.x <= r1.x + r1.width &&
          r1.y <= r2.y + r2.height && r2.y <= r1.y + r1.height);
}

Rectangle intersectRectangles(const Rectangle &r1, const Rectangle &r2) {
  if (isIntersect(r1,r2)) {
    return {max(r1.x, r2.x), max(r1.y, r2.y),
            min(r1.x + r1.width, r2.x + r2.width) - max(r1.x, r2.x),
            min(r1.y + r1.height, r2.y + r2.height) - max(r1.x, r2.x)};
  }
  return {0,0,-1,-1};
}

int main(int argc, char *argv[]) {
  int x1,y1,w1,h1,x2,y2,w2,h2;
  cin >> x1 >> y1 >> w1 >> h1;
  cin >> x2 >> y2 >> w2 >> h2;
  cout << intersectRectangles({x1,y1,w1,h1},{x2,y2,w2,h2}) << '\n';
  return 0;
}
