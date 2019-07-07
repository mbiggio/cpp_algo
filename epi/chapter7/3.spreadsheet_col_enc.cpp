#include <bits/stdc++.h>
using namespace std;

int spreadsheetColumnEncoding(const string &col) {
  int n=0;
  int base = 'Z'-'A'+1;
  for (int i=0; i<col.size(); ++i) {
    n = n*base + (col[i]-'A')+1;
  }
  return n;


}

int main(int argc, char *argv[]) {
  vector<string> tests = {"A","B","D","Y","Z","AA","AB","ZY","ZZ","M","BZ","CCC"};
  for (const string &s : tests) {
    cout << s << " --> " << spreadsheetColumnEncoding(s) << endl;
  }
  return 0;
}
