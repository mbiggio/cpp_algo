#include <bits/stdc++.h>
using namespace std;

bool isValidPart(const string &s) {
  if (s.size() > 3) return false;
  if (s.front() == '0' && s.size() > 1) return false;
  int val = stoi(s);
  return val <= 255 && val >= 0;
}

vector<string> validAddresses(const string &s) {
  vector<string> result;
  for (int i=1; i<4; ++i) {
    string first = s.substr(0,i);
    if (isValidPart(first)) {
      for (int j=1; i+j < s.size() && j<4; ++j) {
	string second = s.substr(i,j);
	if (isValidPart(second)) {
	  for (int k=1; i+j+k < s.size() && k<4; ++k) {
	    string third = s.substr(i+j,k), fourth = s.substr(i+j+k);
	    if (isValidPart(third) && isValidPart(fourth)) {
	      result.emplace_back(first + "." + second + "." + third + "." + fourth);
	    }
	  }
	}
      }
    }
  }
  return result;
}

ostream &operator<<(ostream &os, const vector<string> &vs) {
  for (const string &s : vs) {
    cout << s << endl;
  }
  return os;
}

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  cout << validAddresses(s) << endl;
  return 0;
}
