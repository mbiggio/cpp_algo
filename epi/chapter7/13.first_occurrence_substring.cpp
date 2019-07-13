#include <bits/stdc++.h>
using namespace std;

uint64_t computeHash(const string &s, int start, int end, const uint64_t kBase) {
  uint64_t hash = 0;
  for (int i=start; i<end; ++i) {
    hash = hash*kBase + (uint64_t)(s[i]);
  }
  return hash;
}

bool isEqual(const string &p, const string &t, int offset, uint64_t hashP, uint64_t hashT) {
  if (hashP != hashT) return false;
  for (int i=0; i<p.size(); ++i) {
    if (p[i] != t[i+offset]) return false;
  }
  return true;
}

uint64_t power(uint64_t base, int p) {
  if (p==0) return 1;
  uint64_t half = power(base, p/2);
  return p%2?half*half*base:half*half;
}

int rabinKarp(const string &t, const string &p) {
  const uint64_t kBase = 1<<7;
  const uint64_t kFactor = power(kBase, p.size());
  uint64_t hashP = computeHash(p,0,p.size(),kBase);
  uint64_t hashT = computeHash(t,0,p.size(),kBase);
  if (isEqual(p,t,0,hashP,hashT)) return 0;

  for (int i=p.size(); i<t.size(); ++i) {
    hashT = hashT*kBase + t[i] - kFactor*t[i-p.size()];
    if (isEqual(p,t,i-p.size()+1,hashP,hashT)) return i-p.size()+1;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  string t,p;
  cin >> t >> p;
  cout << rabinKarp(t,p) << '\n';
  return 0;
}
