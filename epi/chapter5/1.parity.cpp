#include <bits/stdc++.h>
using namespace std;

class ParityCalculator {
public:

  static const ParityCalculator &getParityCalculator() {
    static const ParityCalculator calculator;
    return calculator;
  }

  short compute(uint64_t x) const {
    static const uint64_t kMask = 0xFFFF;
    x ^= (x >> 32);
    x ^= (x >> 16);
    return _m[x&kMask];
  }

private:

  ParityCalculator() : _m(1<<16) {
    for (int i=0; i<_m.size(); ++i) _m[i] = parity16(i);
  }

  vector<short> _m; 

  short parity16(uint16_t x) const {
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);
    return x&1;
  }
};


int main(int argc, char *argv[]) {
  uint64_t x;
  cin >> x;
  cout << ParityCalculator::getParityCalculator().compute(x) << '\n';
  return 0;
}
