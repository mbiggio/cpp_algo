#include <bits/stdc++.h>
using namespace std;

class BitReverser {

public:
  static const BitReverser &getBitReverser() {
    static const BitReverser reverser;
    return reverser;
  }

  uint64_t reverse(uint64_t x) const {
    static const uint64_t kMask = 0xFFFF;
    return _m[x & kMask] << (3 * 16) |
           _m[(x >> 16) & kMask] << (2 * 16) |
           _m[(x >> (2 * 16)) & kMask] << 16 |
           _m[(x >> (3 * 16)) & kMask];
  }

private:

  BitReverser() : _m(1<<16) {
    for (int i=0; i<(1<<16); ++i) _m[i] = reverse16(i);
  }

  uint64_t reverse16(uint16_t x) const {
    for (int i=0; i<8; ++i) x = swapBits16(x,i,15-i);
    return x;
  }

  uint16_t swapBits16(uint16_t x, int i, int j) const {
    if (((x >> i)&1) ^ ((x >> j)&1)) {
      return x ^ (1L << i) ^ (1L << j);
    }
    return x;
  }

  vector<uint64_t> _m;

};

int main(int argc, char *argv[]) {
  return 0;
}
