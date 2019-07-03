#include <bits/stdc++.h>
using namespace std;

ostream &operator<<(ostream &os, const vector<int> &v) {
  os << '{';
  for (const int vv : v) os << vv << ' ';
  cout << '}';
  return os;
}

void removeDuplicates(vector<int> &v) {
  int r=0, w=0;
  while(r<v.size()) {
    int cur = v[r];
    while(r<v.size() && v[r]==cur) ++r;
    v[w++] = cur;
  }
  v.erase(v.begin()+w,v.end());
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> v(n);
  default_random_engine gen;
  uniform_int_distribution<> dist(1,n/10);
  for (int i=0; i<n; ++i) v[i] = dist(gen);
  sort(v.begin(),v.end());

  cout << v << '\n';
  removeDuplicates(v);
  cout << v << '\n';
  return 0;
}
