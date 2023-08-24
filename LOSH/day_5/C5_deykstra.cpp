#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

int main(){
    int n, m, a, b, c, x, y, num;
    cin >> n >> m >> x >> y;
    vector <vector<pair<int, int>>> g(n);
    for(int i = 0;i < m;i++){
        cin >> a >> b >> c;
        a--, b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    } 

    vector<int> d(n, 1e9);
    priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> q;
    d[x-1] = 0;
    q.push({0, x-1});
    while (!q.empty()) {
        num = q.top().second;
        q.pop();
        for (auto [u, w] : g[num]) {
            if (d[u] > d[num] + w) {
                d[u] = d[num] + w;
                q.push({d[u], u});
            }
        }
    }

    if (d[y-1] != 1e9) {
        cout << d[y-1] << "\n";
    }
    else {
        cout << -1 << "\n";
    }
    return 0;
}