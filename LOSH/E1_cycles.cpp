#include <bits/stdc++.h> 

using namespace std;

const int maxg = 100000;
vector<int> graph[maxg];
vector<string> visited(maxg, "white");
bool flag = false;
vector<int> res;

void dfs(int v, int ans) {
    if(flag)
        return;
    visited[v] = "grey";
    res.push_back(v);
    for (int u : graph[v]) {
        if (visited[u] == "white") {
            dfs(u, ans);
            if(flag) return;
        }
        else if (visited[u] == "grey"){
            res.push_back(u);
            flag = true;
            ans = u;
            return;
        }  
    }
    visited[v] = "black";
    res.pop_back();
}

int main() {
    int m, u_i, v_i, n;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u_i >> v_i;
        --u_i;
        --v_i;
        graph[u_i].push_back(v_i);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (visited[i] == "white") {
            dfs(i, ans);
        }
    }
    if (flag) {
        bool flag = true;
        res.pop_back();
        cout << "YES\n";
        for(int i : res){
            if(ans == i)
                flag = false;
            if(flag)
                continue;
            cout << i + 1 << " ";
        }
    }

    else {
        cout << "NO\n";
    }

    return 0;
}