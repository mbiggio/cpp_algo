#include <bits/stdc++.h>
using namespace std;

void dutchNationalFlag(vector<int> &v, const int pivot) {

  /* four zones:
   * - 0 <= idx < i  -->  v[idx] < pivot
   * - i <= idx < j  -->  v[idx] = pivot
   * - j <= idx < k  -->  unknown
   * - k <= idx < n  -->  v[idx] > pivot
   */
  int i=0, j=0, k=v.size();
  while (j<k) { // unknown zone not empty
    if (v[j] == pivot) ++j;
    else if (v[j] < pivot) swap(v[i++],v[j++]);
    else swap(v[--k],v[j]);
  }
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (int i=0; i<v.size(); ++i) {
    if (i>0) os << ",";
    os << v[i];
  }
  os << "}";
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  default_random_engine gen;
  uniform_int_distribution<> dist(1,n);
  vector<int> v(n);
  for (int i=0; i<n; ++i) v[i] = dist(gen);
  int pivot = dist(gen);

  cout << "pivot: " << pivot << '\n';
  cout << "v (before): " << v << '\n';
  dutchNationalFlag(v,pivot);
  cout << "v (after ): " << v << '\n';
  return 0;
}
