#include <bits/stdc++.h>
using namespace std;

void helper(const int n, string &result) {
  if (!n) return;
  helper(n/10, result);
  result.push_back(n%10+'0');
}

string intToString(const int n) {
  if (n==0) return "0";
  bool isNegative = n<0;
  int absn = abs(n);

  string result;
  if(isNegative) result.push_back('-');
  helper(absn,result);
  return result;
}

int stringToInt(const string &s) {
  bool isNegative = s[0]=='-';

  int result = 0;
  for (int i = isNegative?1:0; i<s.size(); ++i) {
    result = result*10 + (s[i]-'0');
  }
  return isNegative?-result:result;
}

int main(int argc, char *argv[]) {
  cout << intToString(0) << endl;
  cout << stringToInt("0") << endl;

  cout << intToString(314) << endl;
  cout << stringToInt("314") << endl;

  cout << intToString(-314) << endl;
  cout << stringToInt("-314") << endl;
  return 0;
}
