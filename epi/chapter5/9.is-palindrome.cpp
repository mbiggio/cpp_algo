#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
  if (x<0) return false;
  if (x==0) return true;

  int digits = static_cast<int>(floor(log10(x))+1);
  int power = static_cast<int>(pow(10, digits-1));

  for (int i=0; i<(digits/2); ++i) {
    if (x/power != x%10) return false;
    x %= power;
    x /= 10;
    power /= 100;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int x;
  cin >> x;
  cout << isPalindrome(x) << '\n';
  return 0;
}
