#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;

const int maxg = 100000 + 1;

vector<int> graph[maxg];
vector<int> visited;
vector<int> res;

bool flag = false;

void dfs(int v) {
    visited[v] = 1;
    res.push_back(v);

    for (int to: graph[v]) {
        if (visited[to] == 0) {
            dfs(to);
        } else if (visited[to] == 1) {
            flag = true;

            cout << "YES\n";
            bool c = false;

            for (int i = 0; i < res.size(); ++i) {
                if (res[i] == to) {
                    c = true;
                }
                if (c) {
                    cout << res[i] << " ";
                }

            }
            exit(0);
        }
    }

    visited[v] = 2;
    res.pop_back();
}


int main() {
    int n, m, a, b;
    cin >> n >> m;

    visited.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }

    cout << "NO";

    return 0;
}
