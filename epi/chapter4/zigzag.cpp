#include <bits/stdc++.h>
using namespace std;


template <typename T>
struct trait {
  typedef T& value;
};

template <>
struct trait <int> {
  typedef int value;
};

template <typename T>
void print(const vector<T> &v) {
  for (const typename trait<T>::value t : v) cout << t << " ";
  cout << '\n';
};

template <typename T>
void zigzag(vector<T> &v) {
  for (int i=1; i<v.size(); ++i) {
    if (i%2==1 && v[i] < v[i-1] ||
	i%2==0 && v[i] > v[i-1]) {
      swap(v[i-1],v[i]);
    }
  }
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  default_random_engine generator;
  uniform_int_distribution<int> distribution(0,n-1);
  vector<int> v(n);
  for (int i=0; i<n; ++i) v[i] = distribution(generator);

  print(v);
  zigzag(v);
  print(v);

  return 0;
}
