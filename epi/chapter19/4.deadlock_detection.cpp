#include <bits/stdc++.h>
using namespace std;
using Color = enum {WHITE, GREY, BLACK};

bool hasCycleHelper(const unordered_map<int,vector<int>> &adj, 
                    unordered_map<int,Color> &vertexStatus,
		    const int current) {

  vertexStatus[current] = GREY;
  for (const int n : adj.at(current)) {
    if (vertexStatus[n] == GREY) return true;
    else if (vertexStatus[n] == WHITE) {
      if (hasCycleHelper(adj,vertexStatus,n)) return true;
    }
  }
  vertexStatus[current] = BLACK;
  return false;
}

bool hasCycle(const unordered_map<int,vector<int>> &adj) {
  unordered_map<int,Color> vertexStatus;
  for (const unordered_map<int,vector<int>>::value_type &value : adj) {
    vertexStatus[value.first] = WHITE;
  }
  
  for (const unordered_map<int,vector<int>>::value_type &value : adj) {
    if (vertexStatus[value.first] == WHITE) {
      if (hasCycleHelper(adj,vertexStatus,value.first)) return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  {
    unordered_map<int, vector<int>> adj = {
      {0, {2}},
      {1, {0}},
      {2, {1,3}},
      {3, {}}
    };

    cout << hasCycle(adj)<< '\n';
  }
  {
    unordered_map<int, vector<int>> adj = {
      {0, {1,2}},
      {1, {}},
      {2, {1,3}},
      {3, {}}
    };

    cout << hasCycle(adj)<< '\n';
  }
  return 0;
}
