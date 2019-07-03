#include <bits/stdc++.h>
using namespace std;

int32_t reverseDigits(int32_t x) {
  bool isNegative = x<0;
  if (isNegative) x = -x;
  int32_t result = 0;
  while(x) {
    result = 10*result + x%10;
    x /= 10;
  }
  return isNegative?-result:result;
}

int main() {
  int32_t x;
  cin >> x;
  cout << reverseDigits(x) << '\n';
  return 0;
}
