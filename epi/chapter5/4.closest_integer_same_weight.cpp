#include <bits/stdc++.h>
using namespace std;

uint64_t closestIntegerSameWeight(uint64_t x) {
  for (int i=1; i<64; ++i) {
    if (((x>>(i-1))&1) != ((x>>i)&1)) {
      x ^= (1UL<<(i-1)) | (1UL<<i);
      return x;
    }
  }
  throw invalid_argument("all bits are 1 or 0");
}

int main(int argc, char *argv[]) {
  uint64_t x;
  cin >> x;
  cout << closestIntegerSameWeight(x) << '\n';
  return 0;
}
