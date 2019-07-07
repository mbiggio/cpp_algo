#include <bits/stdc++.h>
using namespace std;

template <typename T>
class OnlineSampler;

template <typename T>
OnlineSampler<T> &operator<<(OnlineSampler<T> &os, const T &val);

template <typename T>
class OnlineSampler {
public:  
  OnlineSampler(int k): _sampleSize(k), _readItems(0), _gen(), _sample() {};
  const vector<T> &getSample() const {
    return _sample;
  };

  friend OnlineSampler<T> &operator<< <T>(OnlineSampler<T> &os, const T &val);

private:
  void get(const T &val) {
    ++_readItems;

    if (_sample.size() < _sampleSize) {
      _sample.emplace_back(val);
      return;
    }

    int randIdx = uniform_int_distribution<>{0,_readItems-1}(_gen);
    if (randIdx < _sampleSize) {
      _sample[randIdx] = val;
    }
  }

private:
  int _sampleSize;
  int _readItems;
  default_random_engine _gen;
  vector<T> _sample;
};

template <typename T>
OnlineSampler<T> &operator<<(OnlineSampler<T> &os, const T &val) {
  os.get(val);
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i=0; i<v.size(); ++i) os << v[i] << ' ';
  return os;
}


int main(int argc, char *argv[]) {
  int k,n;
  cin >> k;
  OnlineSampler<int> os(k);
  while (cin >> n) {
    os << n;
    cout << os.getSample() << endl;
  }
  return 0;
}
