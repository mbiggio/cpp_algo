#include <bits/stdc++.h>
using namespace std;

using Color = enum {WHITE, BLACK, UNDEFINED};
Color flip(const Color c) {
  return c==WHITE?BLACK:c==BLACK?WHITE:UNDEFINED;
}

bool isBipartiteHelper(const vector<vector<int>> &adj, 
                       vector<Color> &colors, 
		       const int curNode, 
		       const Color curColor) {

  colors[curNode] = curColor;
  for (const int n : adj[curNode]) {
    if (colors[n] == UNDEFINED) {
      if (!isBipartiteHelper(adj,colors,n,flip(curColor))) return false;
    }
    else if (colors[n] == curColor) return false;
  }
  return true;
}

bool isBipartite(const vector<vector<int>> &adj) {
  vector<Color> colors(adj.size(), UNDEFINED);
  for (int i=0; i<adj.size(); ++i) {
    if (colors[i] == UNDEFINED) {
      if (!isBipartiteHelper(adj,colors,i,WHITE)) return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  {
    vector<vector<int>> adj = {
      {1},
      {2},
      {0}
    };
    cout << isBipartite(adj) << '\n';
  }
  {
    vector<vector<int>> adj = {
      {1},
      {2},
      {3},
      {0}
    };
    cout << isBipartite(adj) << '\n';
  }
  return 0;
}
