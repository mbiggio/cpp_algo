#include <bits/stdc++.h>
using namespace std;

/***** printing utilities *****/
ostream &operator<<(ostream &os, const vector<int> &v) {
  os << "{ ";
  for (const int vv : v) os << vv << ' ';
  os << "} ";
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const unordered_map<int,T> &v) {
  os << "{ ";
  for (const typename unordered_map<int,T>::value_type &t : v) os << t.second << ' ';
  os << "} ";
  return os;
}



/***** weighted graph data structures definitions *****/
struct vertex {
  int id;
  int estimatedDistance;
  int predecessor;
  bool operator<(const vertex &other) const {
    if (estimatedDistance < other.estimatedDistance) return true;
    if (estimatedDistance == other.estimatedDistance && id < other.id) return true;
    return false;
  }

  friend ostream &operator<<(ostream &os, const vertex &v);
};

ostream &operator<<(ostream &os, const vertex &v) {
  os << "{" << v.id << ',' << v.predecessor << "}";
  return os;
}

struct edge {
  int start, end;
  int weight;
};

/***** initialization of unexplored set *****/
set<vertex> initializeUnexplored(const vector<vector<edge>> &adj, const int start) {
  set<vertex> unexplored;
  for (int i=0; i<adj.size(); ++i) unexplored.insert({i,numeric_limits<int>::max(),-1});
  for (const edge &e : adj[start]) unexplored.insert({e.end,e.weight,start});
  return unexplored;
}

void fillResult(const unordered_map<int, vertex> &explored,
                const int end,
		vector<int> &result) {
  if (end == -1) return;
  fillResult(explored, explored.at(end).predecessor, result);
  result.emplace_back(end);
}

/***** Dijkstra's shortest path algorithm *****/
vector<int> shortestPath(const vector<vector<edge>> &adj, const int start, const int end) {
  set<vertex> unexplored = initializeUnexplored(adj,start);
  unordered_map<int, vertex> explored{{start,vertex{start,0,-1}}};

  while (explored.size() < adj.size()) {
    vertex chosen = *unexplored.begin();
    unexplored.erase(unexplored.begin());
    if (!explored.count(chosen.id)) {
      explored[chosen.id] = chosen;
      for (const edge &e : adj[chosen.id]) {
	unexplored.insert({e.end,
	                   chosen.estimatedDistance==numeric_limits<int>::max()?
			     chosen.estimatedDistance:
			     e.weight+chosen.estimatedDistance,
			   chosen.id});
      }
    }
  }

  if (explored[end].predecessor == -1) return {};
  vector<int> result;
  fillResult(explored,end,result);
  return result;
}

int main(int argc, char *argv[]) {
  {
    vector<vector<edge>> adj = {
      {{0,1,7},{0,2,9},{0,5,14}},
      {{1,0,7},{1,2,10},{1,3,15}},
      {{2,0,9},{2,1,10},{2,3,11},{2,5,2}},
      {{3,1,15},{3,2,11},{3,4,6}},
      {{4,3,6},{4,5,9}},
      {{5,0,14},{5,2,2},{5,4,9}}
    };

    cout << shortestPath(adj,0,4) << '\n';
  }
  return 0;
}
