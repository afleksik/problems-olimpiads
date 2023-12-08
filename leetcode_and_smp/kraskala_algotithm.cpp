#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

class DSU {
private:
  vector<int> parent;
  vector<int> size;
  
public:
  DSU(int n) : parent(n, -1), size(n, 1) {}

  int find(int x) {
   	if (parent[x] != -1) {
      parent[x] = x;
      return x;
    }
    return parent[x] = find(parent[x]);
  }

  void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (size[x] < size[y]) {
        swap(x, y);
      }
      parent[y] = x;
      size[x] += size[y];
	
  }

}
};


int main() {
  int n, m, u, v, p;
  cin >> n >> m;

  vector<tuple<int, int, int>> graph;

  for (int i = 0; i < m; ++i){
    cin >> p >> v >> u;
    graph.push_back(make_tuple(p, v - 1, u - 1));
  }

  sort(graph.begin(), graph.end());
  DSU dsu(n);

  int count = 0;
  
  for (int i = 0; i < n; ++i) {
    auto [p, v, u] = graph[i];

    if (dsu.find(v) != dsu.find(u)) {
      dsu.union_set(v, u);
      count += p;
    }
  }
	
  cout << p;
	return 0;
}