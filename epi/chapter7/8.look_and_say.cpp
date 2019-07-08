#include <bits/stdc++.h>
using namespace std;

string next(const string &current) {
  string result;
  for (int j=0; j<current.size();) {
    char c = current[j++];
    int num = 1;
    while (j<current.size() && current[j]==c) {
      ++num; 
      ++j;
    }
    result.append(to_string(num)).push_back(c);
  }
  return result;
}


string lookAndSay(const int n) {
  if (n<1) throw invalid_argument("n must be >= 1");
  string result = "1";
  for (int i=1; i<n; ++i) result = next(result);
  return result;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  cout << lookAndSay(n) << endl;
  return 0;
}
