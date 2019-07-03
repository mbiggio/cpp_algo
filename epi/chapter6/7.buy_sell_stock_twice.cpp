#include <bits/stdc++.h>
using namespace std;

double buySellStockTwice(const vector<double> &v) {
  if (v.empty()) return 0.0;
  vector<double> bestSell(v.size(),0.0);
  double currentMin = v.front(), currentGain = 0.0;
  for (int i=1; i<v.size(); ++i) {
    currentGain = max(currentGain, v[i]-currentMin);
    currentMin = min(currentMin, v[i]);
    bestSell[i] = currentGain;
  }

  double currentMax = v.back();
  for (int i=v.size()-2; i>=2; --i) {
    currentGain = max(currentGain, currentMax-v[i]+bestSell[i-1]);
    currentMax = max(currentMax, v[i]);
  }

  return currentGain;
}

int main(int argc, char *argv[]) {
  const vector<double> v{12,11,13,9,12,8,14,13,15};
  cout << buySellStockTwice(v) << '\n';
  return 0;
}
