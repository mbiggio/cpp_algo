#include <bits/stdc++.h>
using namespace std;

template <typename T>
void sampleOffline(vector<T> &v, int k) {
  default_random_engine gen;  
  for (int i=0; i<k; ++i) {
    swap(v[i], v[uniform_int_distribution<>{i,v.size()-1}(gen)]);
  }
}

int main(int argc, char *argv[]) {
  return 0;
}
