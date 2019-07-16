#include <bits/stdc++.h>
using namespace std;

ostream &operator<<(ostream &os, const vector<int> &v) {
  for (const int item : v) os << item << ' ';
  return os;
}

void dfs(const vector<vector<int>> &adj,
         vector<bool> &discovered,
         vector<bool> &visited,
	 stack<int> &s,
	 const int node) {

  discovered[node] = true;
  for (const int neighbor : adj[node]) {
    if (!discovered[neighbor]) dfs(adj,discovered,visited,s,neighbor);
    else if (!visited[neighbor]) {
      throw invalid_argument("graph is not acyclic");
    }
  }
  visited[node] = true;
  s.push(node);
}

vector<int> topologicalOrdering(const vector<vector<int>> &adj) {
  stack<int> s;
  vector<bool> discovered(adj.size(),false);
  vector<bool> visited(adj.size(),false);
  for (int i=0; i<adj.size(); ++i) {
    if (!discovered[i]) {
      dfs(adj,discovered,visited,s,i);
    }
  }

  vector<int> result;
  while(!s.empty()) {
    result.emplace_back(s.top());
    s.pop();
  }
  return result;
}

vector<int> longestPath(const vector<vector<int>> &adj) {
  vector<int> ordering = topologicalOrdering(adj);

  vector<int> successor(adj.size(),-1), length(adj.size(),0);
  int maxLength = 1, maxStart = adj.size()-1;
  for (int i=ordering.size()-1; i>=0; --i) {
    for (int j=0; j<adj[i].size(); ++j) {
      if (length[i] < length[adj[i][j]]+1) {
	length[i] = length[adj[i][j]]+1;
	successor[i] = adj[i][j];
      }
    }
    if (maxLength < length[i]) {
      maxLength = length[i];
      maxStart = i;
    }
  }

  vector<int> result{maxStart};
  while (successor[maxStart] != -1) {
    result.emplace_back(successor[maxStart]);
    maxStart = successor[maxStart];
  }
  return result;
}

int main(int argc, char *argv[]) {
  {
    vector<vector<int>> adj = {
      {},
      {0},
      {0},
      {0},
      {0},
      {4,0}
    };
    cout << longestPath(adj) << '\n';
  }
  {
    vector<vector<int>> adj = {
      {2},
      {0},
      {1}
    };
    try {
      longestPath(adj);
    }
    catch(const invalid_argument &exc) {
      cout << exc.what() << '\n';
    }
  }
  return 0;
}
