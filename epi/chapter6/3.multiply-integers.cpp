#include <bits/stdc++.h>
using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i=0; i<v.size(); ++i) os << v[i];
  return os;
}

vector<int> multiply(vector<int> v1, vector<int> v2) {
  int sign = (v1.front() < 0 ^ v2.front() < 0)?-1:1;
  v1.front() = abs(v1.front()); v2.front() = abs(v2.front());

  vector<int> result(v1.size() + v2.size(), 0);
  for (int i=v1.size()-1; i>=0; --i) {
    for (int j=v2.size()-1; j>=0; --j) {
      result[i+j+1] += v1[i]*v2[j];
      result[i+j] += result[i+j+1]/10;
      result[i+j+1] %= 10;
    }
  }

  result = vector<int>{find_if(begin(result), end(result), [](int a) {return a;}), end(result)};
  if (result.empty()) return {0};
  result.front() *= sign;
  return result;
}

int main(int argc, char *argv[]) {
  vector<int> v1{1,9,3,7,0,7,7,2,1}, v2{-7,6,1,8,3,8,2,5,7,2,8,7};
  cout << multiply(v1,v2) << '\n';
  return 0;
}
