#include <bits/stdc++.h>
using namespace std;

int removeAndCount(string &s, const int size, const char c1, const char c2, int &numC2) {
  int w = 0;
  numC2 = 0;
  for (int r=0; r<size; ++r) {
    if (s[r] == c2) ++numC2;
    if (s[r] != c1) s[w++] = s[r];    
  }
  return w;
}

int replaceAndRemove(string &s, const int size) {
  int numA = 0;
  int newSize = removeAndCount(s,size,'b','a',numA);
  int newNewSize = newSize + numA;

  for (int w = newNewSize-1, r = newSize-1; r>=0; --r) {
    if (s[r] == 'a') {
      s[w--] = 'd';
      s[w--] = 'd';
    }
    else {
      s[w--] = s[r];
    }
  }
  return newNewSize;
}

int main(int argc, char *argv[]) {
  vector<string> vs = {"abac_","acaa___"};

  for (string &s : vs) {
    int size = replaceAndRemove(s, 4);
    for (int i=0; i<size; ++i) cout << s[i];
    cout << '\n';
  }
  return 0;
}
