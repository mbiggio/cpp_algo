#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  for (const T vv : v) os << vv << ' ';
  os << '}';
  return os;
}

vector<int> enumeratePrimes(int n) {
  vector<int> result;
  vector<bool> isPrime(n+1,true);
  for (int x=2; x<=n; ++x) {
    if (isPrime[x]) {
      result.push_back(x);
      for (int y=2; y*x<=n; ++y) isPrime[y*x] = false;
    }
  }
  return result;
}


int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  cout << enumeratePrimes(n) << '\n';
  return 0;
}
