#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s) {
  int i=0, j=s.size()-1;
  while (i<j) {
    if (!isalnum(s[i])) ++i;
    else if (!isalnum(s[j])) --j;
    else {
      if (tolower(s[i++]) != tolower(s[j--])) return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  cout << isPalindrome("A man, a plan, a canal, Panama.") << endl;
  cout << isPalindrome("Able was I, ere I saw Elba!") << endl;
  cout << isPalindrome("Ray a Ray") << endl;
  return 0;
}
