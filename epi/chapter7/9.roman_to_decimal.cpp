#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(const string &s) {
  static const unordered_map<char,int> m{
    {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
  };

  int n=0;
  for (int i=0; i<s.size(); ++i) {    
    if (i<s.size()-1 && m.at(s[i]) < m.at(s[i+1])) {
      n += m.at(s[i+1]) - m.at(s[i]);
      ++i;
    }
    else {
      n += m.at(s[i]);
    }
  }
  return n;
}

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  cout << romanToDecimal(s) << endl;
  return 0;
}
