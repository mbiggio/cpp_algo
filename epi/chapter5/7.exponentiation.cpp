#include <bits/stdc++.h>
using namespace std;

double helper(double x, int y) {
  if (y == 0) return 1.0;
  double tmp = helper(x,y/2);
  return y%2?x*tmp*tmp:tmp*tmp;
}

double power(double x, int y) {
  if (x == 0.0) return 0.0;
  if (y < 0) {
    y = -y;
    x = 1.0/x;
  }
  return helper(x,y);
}

int main(int argc, char *argv[]) {
  double x; int y;
  cin >> x >> y;
  cout << power(x,y) << '\n';
  return 0;
}
