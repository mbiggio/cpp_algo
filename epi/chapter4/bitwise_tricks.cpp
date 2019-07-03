#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  int x;
  cin >> x;

  cout << "x = " << x << endl;
  cout << "isolate rightmost bit set to 1 = " << (x & ~(x-1)) << endl;
  cout << "remove rightmost bit set to 1 = " << (x & (x-1)) << endl;
  cout << "remove rightmost bit set to 1 = " << (x & (x-1)) << endl;
  cout << "right-propagate rightmost bit set to 1 = " << (x | (x-1)) << endl;
  cout << "right-propagate rightmost bit set to 1 = " << (x | (x-1)) << endl;
  cout << "modulo 64 (1<<6) = " << (x & ((1<<6)-1)) << endl;
  cout << "is power of two? = " << ((x & (x-1)) == 0) << endl;
  return 0;
}
