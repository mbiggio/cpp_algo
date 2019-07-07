#include <bits/stdc++.h>
using namespace std;

template <typename T>
void applyPermutation(vector<T> &v, vector<int> &p) {
  for (int i=0; i<v.size(); ++i) {
    int j=i;
    T val = v[j];
    while (p[j] >= 0) {      
      swap(v[p[j]],val);
      int tmp = p[j];
      p[j] = p[j]-p.size();
      j = tmp;
    }
  }
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i=0; i<v.size(); ++i) os << v[i] << " ";
  return os;
}

int main(int argc, char *argv[]) {
  vector<int> p{2,0,1,3};
  vector<char> v{'a','b','c','d'};
  applyPermutation(v,p);
  cout << v << '\n';
  return 0;
}
