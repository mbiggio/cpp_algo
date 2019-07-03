#include <bits/stdc++.h>
using namespace std;

uint64_t add(uint64_t a, uint64_t b) {
  uint64_t result = 0;
  short carry = 0;
  for (int i=0; i<64; ++i) {
    short ai = ((a>>i)&1), bi = ((b>>i)&1);
    result |= (ai ^ bi ^ carry) << i;
    carry = (ai & bi) | (ai & carry) | (bi & carry);
  }
  return result;
}

uint64_t multiply(uint64_t a, uint64_t b) {
  if (b == 0) return 0;
  uint64_t m = multiply(a,(b>>1));
  return b%2?add(m<<1,a):(m<<1);
}

int main(int argc, char *argv[]) {
  uint64_t a,b;
  cin >> a >> b;
  cout << multiply(a,b) << '\n';
  return 0;
}
