#include <bits/stdc++.h>
using namespace std;

template <typename T>
void randomPermutation(vector<T> &v) {
  default_random_engine gen((random_device())());
  for (int i=0; i<v.size()-1; ++i) {
    swap(v[i],v[uniform_int_distribution<>{i,static_cast<int>(v.size()-1)}(gen)]);
  }
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i=0; i<v.size(); ++i) os << v[i] << ' ';
  return os;
}

int main(int argc, char *argv[]) {
  vector<int> v{0,1,2,3,4,5,6,7,8,9};
  randomPermutation(v);
  cout << v << endl;
  return 0;
}
