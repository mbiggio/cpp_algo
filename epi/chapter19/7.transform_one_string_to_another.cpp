#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (const T &t : v) os << t << ' ';
  return os;
}

vector<string> produce(const string &start,
                       const string &end,
		       const unordered_set<string> &dict) {

  unordered_map<string,string> predecessor;
  queue<string> q;
  q.emplace(start);
  predecessor[start] = "";
  while(!q.empty()) {
    string current = q.front();
    q.pop();
    for (int i=0; i<current.size(); ++i) {
      for (char c='a'; c<='z'; ++c) {
	if (c == current[i]) continue;
	string candidate = current;
	candidate[i] = c;
	if (!dict.count(candidate) || predecessor.count(candidate)) continue;
	predecessor[candidate] = current;
	q.emplace(candidate);
      }
    }
  }

  if (!predecessor.count(end)) return {};
  vector<string> result = {end};
  while (predecessor[result.back()] != "") {
    result.emplace_back(predecessor[result.back()]);
  }
  reverse(result.begin(), result.end());
  return result;
}

int main(int argc, char *argv[]) {
  string start = "cat", end = "dog";
  unordered_set<string> dict = {
    "bat", "cot","dog","dag","dot","cat"
  };
  cout << produce(start, end, dict) << '\n';
  return 0;
}
