#include <bits/stdc++.h>
using namespace std;

void reverseWords(string &s) {
  // at the beginning of each iteration, i is at the beginning of a word, or past the last char
  for (int i=0; i<s.size();) {
    int j=i;
    while (j<s.size() && s[j] != ' ') ++j;
    reverse(s.begin()+i, s.begin()+j);
    i = j<s.size()?j+1:j;
  }
  reverse(s.begin(),s.end());
}

int main(int argc, char *argv[]) {
  string s = "Bob likes Alice";
  reverseWords(s);
  cout << s << endl;
}
