#include <bits/stdc++.h>
using namespace std;

bool isNumber(const char c) {
  return (c >= '0' && c <= '9');
}

string encode(const string &s) {
  string encoded;
  for (int i=0; i<s.size();) {
    char current = s[i];
    int occurrences = 1;
    int j = i+1;
    while (j<s.size() && s[j]==current) {
      ++j; ++occurrences;
    }
    encoded += to_string(occurrences);
    encoded.push_back(current);
    i=j;
  }
  return encoded;
}

string decode(const string &s) {
  string result;
  for (int i=0; i<s.size();) {
    int j=i;
    int occurrences=0;
    while(isNumber(s[j])) {
      occurrences = occurrences*10 + (s[i]-'0');
      ++j;
    }
    for (int k=0; k<occurrences; ++k) result.push_back(s[j]);
    i = j+1;
  }
  return result;
}

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  cout << "original: " << s << '\n';
  cout << "encoded : " << encode(s) << '\n';
  cout << "decoded : " << decode(encode(s)) << '\n';
  return 0;
}
