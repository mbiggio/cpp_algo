#include <bits/stdc++.h>
using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (int i=0; i<v.size(); ++i) {
    if (i>0) os << ",";
    os << v[i];
  }
  os << "}";
}

void increment(vector<int> &v) {
  int carry = 1, i=v.size()-1;
  for (; carry && i>=0; --i) {
    v[i] += carry;
    carry = v[i]/10;
    v[i] %= 10;
  }

  if (i == -1 && carry) v.insert(v.begin(),carry);
}

int main(int argc, char *argv[]) {
  vector<int> v = {9,9,9};
  cout << "v (before) : " << v << '\n';
  increment(v);
  cout << "v (after ) : " << v << '\n';
  return 0;
}
