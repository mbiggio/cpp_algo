#include <bits/stdc++.h>
using namespace std;

default_random_engine generator;

int uniforamRandom(int a, int b) {
  uniform_int_distribution<> distribution(0,1);
  int ub = b-a+1, result;
  do {
    result = 0;
    for (int i=0; (1<<i)<ub; ++i) {
      if (distribution(generator)) result |= (1<<i);
    }
  } while (result >= ub);
  return result + a;
}

int main(int argc, char *argv[]) {
  int N,a,b;
  cin >> N >> a >> b;
  for (int i=0; i<N; ++i) cout << uniforamRandom(a,b) << '\n';
  return 0;
}
