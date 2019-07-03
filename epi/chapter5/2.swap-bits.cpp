#include <bits/stdc++.h>
using namespace std;

uint64_t swapBits(uint64_t x, int i, int j) {
  if (((x >> i)&1) ^ ((x >> j)&1)) {
    return x ^ (1L << i) ^ (1L << j);
  }
  return x;
}



int main(int argc, char *argv[]) {
  uint64_t x;
  int i,j;
  cin >> x >> i >> j;
  cout << swapBits(x,i,j) << '\n';
  return 0;
}
