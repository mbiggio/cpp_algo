#include <bits/stdc++.h>
using namespace std;

void helper(const string &number, const int idx, string &soFar, vector<string> &result) {
  static const vector<string> kNumToChars = {
    "0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"
  };

  if (idx == number.size()) {
    result.emplace_back(soFar);
  }

  const string &cand = kNumToChars[number[idx]-'0'];
  for (const char c : cand) {
    soFar.push_back(c);
    helper(number, idx+1, soFar, result);
    soFar.pop_back();
  }
}

vector<string> phoneNumberMnemonics(const string &number) {
  vector<string> result;
  string soFar;
  helper(number,0,soFar,result);
  return result;
}

int main(int argc, char *argv[]) {
  vector<string> r = phoneNumberMnemonics("2276696");
  for (const string &s : r) {
    cout << s << endl;
  }
  return 0;
}
