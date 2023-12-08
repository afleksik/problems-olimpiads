#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

int abc(){
	int n, m, a, b, c, x, y, num;
	int weight = 0;
	cin >> n >> m >> x >> y;
	vector <vector<pair<int, int>>> g(n);
	vector<bool> used(n);
  
  
  for(int i = 0;i < m;i++){
		cin >> a >> b >> c;
		a--, b--;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	} 

	priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, x-1});
	while (!q.empty()) {
		auto [v, num] = q.top();
		q.pop();
		if (used[v]) continue;
    	used[v] = true;

    	weight += num;
    
		for (auto [u, w] : g[num]) {
			if (!used[u]) {
				
				q.push({u, w});
			}
		}
	}
	cout << weight;

	return 0;
}