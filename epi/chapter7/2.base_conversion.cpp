#include <bits/stdc++.h>
using namespace std;

void constructFromBase(int n, int b, string &result) {
  if (!n) return;
  constructFromBase(n/b, b, result);
  int rem = n%b;
  result.push_back(rem<10 ? rem+'0' : rem-10+'A');
}

string baseConvertion(const string &s, int b1, int b2) {
  if (s == "0" || s == "-0") return "0";
  bool isNegative = s[0]=='-';
  int x = 0;
  for (int i = isNegative?1:0; i<s.size(); ++i) {
    x *= b1;
    x += isdigit(s[i])?  s[i]-'0' : s[i] - 'A' + 10;
  }

  string result;
  if (isNegative) result.push_back('-');
  constructFromBase(x,b2,result);
  return result;
}

int main(int argc, char *argv[]) {
  cout << baseConvertion("0",7,13) << endl;
  cout << baseConvertion("-0",7,13) << endl;
  cout << baseConvertion("615",7,13) << endl;
  return 0;
}
