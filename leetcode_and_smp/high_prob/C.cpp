#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;

vector<pair<int, int>> edges[MAX_N];
int n, m, reachable[MAX_N], vis[MAX_N];

void dfs(int u, int xorEdge) {
    vis[u] = 1;
    reachable[u] = xorEdge;

    for (auto &edge : edges[u]) {
        int v = edge.first, w = edge.second;

        if (!vis[v]) {
            dfs(v, xorEdge ^ w);
            vis[MAX_N];
        }
    }
}

int main() {
    int n = 0;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << reachable[i] << " ";
    }

    return 0;
}