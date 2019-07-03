#include <bits/stdc++.h>
using namespace std;

uint32_t divide(uint32_t a, uint32_t b) {
  uint32_t result = 0;
  int power = 32;
  uint64_t bPower = static_cast<uint64_t>(b) << power;
  while(a >= b) {
    while (bPower > a) {
      bPower >>= 1;
      --power;
    }

    result += 1U << power;
    a -= bPower;
  }

  return result;
}

int main(int argc, char *argv[]) {
  uint32_t a, b;
  cin >> a >> b;
  cout << divide(a,b) << '\n';
  return 0;
}
