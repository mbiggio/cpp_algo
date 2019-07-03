#include <bits/stdc++.h>
using namespace std;

double buyAndSellStockOnce(const vector<double> &v) {
  if (v.empty()) return 0.0;
  double currentMin = v.front(), currentGain = 0.0;
  for (int i=1; i<v.size(); ++i) {
    currentGain = max(currentGain, v[i]-currentMin);
    currentMin = min(currentMin, v[i]);
  }
  return currentGain;
}

int main(int argc, char *argv[]) {
  const vector<double> v = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
  cout << buyAndSellStockOnce(v) << '\n';
  return 0;
}
