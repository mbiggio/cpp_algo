#include <bits/stdc++.h>
using namespace std;

vector<int> randomSubset(const int n, const int k) {
  unordered_map<int,int> m;
  default_random_engine gen((random_device())());

  for (int i=0; i<k; ++i) {
    int randIdx = uniform_int_distribution<>{i,n-1}(gen);
    // need to swap a[i] and a[randIdx]
    if (m.count(i) && m.count(randIdx)) {
      swap(m[i],m[randIdx]);
    }
    else if (!m.count(i) && m.count(randIdx)) {
      m[i] = m[randIdx];
      m[randIdx] = i;
    }
    else if (m.count(i) && !m.count(randIdx)) {
      m[randIdx] = m[i];
      m[i] = randIdx;
    }
    else {
      m[randIdx] = i;
      m[i] = randIdx;
    }
  }

  vector<int> result;
  for (int i=0; i<k; ++i) result.emplace_back(m[i]);
  return result;
}

ostream &operator<<(ostream &os, const vector<int> &v) {
  for (int i=0; i<v.size(); ++i) cout << v[i] << ' ';
  return os;
}

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  cout << randomSubset(n,k) << endl;
  return 0;
}
