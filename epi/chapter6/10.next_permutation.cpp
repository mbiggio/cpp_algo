#include <bits/stdc++.h>
using namespace std;

template <typename T>
void nextPermutation(vector<T> &v) {
  for (int i=v.size()-2; i>=0; --i) {
    if (v[i] < v[i+1]) {
      sort(v.begin()+i+1, v.end());
      auto it = upper_bound(v.begin()+i+1,v.end(),v[i]);
      iter_swap(v.begin()+i,it);
      return;
    }
  }
  throw runtime_error("no next permutation");
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i=0; i<v.size(); ++i) os << v[i] << ' ';
  return os;
}

int main(int argc, char *argv[]) {
  {
    vector<int> v{1,0,3,2};
    nextPermutation(v);
    cout << v << '\n';
  }
  {
    vector<int> v{3,2,1,0};
    try {
      nextPermutation(v);
    } catch(const runtime_error &ex) {
      cout << ex.what() << '\n';
      return 0;
    }
    cout << v << '\n';
  }
  return 0;
}
