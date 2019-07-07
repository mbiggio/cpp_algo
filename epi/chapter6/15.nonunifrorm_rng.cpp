#include <bits/stdc++.h>
using namespace std;

class NonUniformRandomNumberGenerator {
public:

  NonUniformRandomNumberGenerator(const vector<int> &numbers,
                                  const vector<double> &probabilities) : 
    _cumulative(generateCumulative(probabilities)), _numbers(numbers), gen((random_device())()) {
  }

  int get() {
    double p = uniform_real_distribution<>{0.0, 1.0}(gen);
    auto it = lower_bound(_cumulative.begin(), _cumulative.end(), p);
    return _numbers[it-_cumulative.begin()];
  }

private:

  vector<double> generateCumulative(const vector<double> &probabilities) {
    vector<double> cumulative(probabilities.size());
    cumulative[0] = probabilities[0];
    for (int i=1; i<cumulative.size(); ++i) cumulative[i] = cumulative[i-1] + probabilities[i];
    return cumulative;
  }

  const vector<double> _cumulative;
  const vector<int> _numbers;
  mt19937 gen;

};

int main(int argc, char *argv[]) {
  vector<int> numbers{3,5,7,11};
  vector<double> probabilities{9.0/18.0, 6.0/18.0, 2.0/18.0, 1.0/18.0};
  int n;
  cin >> n;

  unordered_map<int,int> m;
  NonUniformRandomNumberGenerator g(numbers,probabilities);
  for (int i=0; i<n; ++i) ++m[g.get()];

  for (const unordered_map<int,int>::value_type &p : m) {
    cout << p.first << ":" << p.second << endl;
  }
  return 0;
}
