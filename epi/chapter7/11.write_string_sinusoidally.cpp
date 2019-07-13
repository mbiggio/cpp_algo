#include <bits/stdc++.h>
using namespace std;

string writeSinusoidally(const string &s) {

  string result;
  // upper layer
  for (int i=1; i<s.size(); i+=4) result.push_back(s[i]);
  for (int i=0; i<s.size(); i+=2) result.push_back(s[i]);
  for (int i=3; i<s.size(); i+=4) result.push_back(s[i]);
  return result;
}

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  cout << writeSinusoidally(s) << '\n';
  return 0;
}
