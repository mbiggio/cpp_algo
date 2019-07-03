#include <bits/stdc++.h>
using namespace std;

bool canReachEnd(const vector<int> &v) {
  int maxReachable = 0;
  for (int i=0; i<v.size(); ++i) {
    if (i>maxReachable) return false;
    maxReachable = max(maxReachable, i+v[i]);
  }
  return true;
}

int main(int argc, char *argv[]) {
  cout << canReachEnd({3,3,1,0,2,0,1}) << endl;
  cout << canReachEnd({3,2,0,0,2,0,1}) << endl;
  return 0;
}
