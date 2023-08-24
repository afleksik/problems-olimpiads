/*


Дан ориентированный ацикличный граф GG. Проверить, что существует
единственный топологический порядок вершин графа.

Формат ввода
Первая строка входных данных содержит число вершин графа n
(1≤n≤1000001≤n≤100000) и число ребер графа mm (0≤m≤1000000≤m≤100000). Следующие m 
строк содержат пары чисел от 11 до nn, задающие начало и конец соответствующего ребра.
Гарантируется, что граф не содержит циклов.

Формат вывода
Если топологический порядок единственный, выведите на первой строке YES, а на второй 
номера вершин в топологическом порядке, иначе выведите NO.

*/

#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long long ll;
typedef string str;

const ll N = 1e5 + 6761;

ll gr, bl;
vector <ll> used, ans, color;
vector <vector<ll>> G;

void dfs(ll v){
    color[v] = 1;
    used[v] = 1;
    for(auto &u : G[v]){
        if(!used[u]){
            dfs(u);
        }else if(color[u] == 1){
            cout << -1 << '\n';
            exit(0);
        }
    }
    ans.push_back(v);
    color[v] = 2;
}

void solve() {
    ll n, m, x, y;
    cin >> n >> m;
    used.assign(n, 0);
    color.assign(n, 0);
    G.assign(n, vector<ll> (0));
    for(int i = 0;i < m;i++){
        cin >> x >> y;
        G[x-1].push_back(y-1);
    }
    for(int i = 0;i < n;i++){
        if(!used[i]) dfs(i);
    }
    reverse(all(ans));
    ll curr;
    for(int i = 1;i < n;i++){
        curr = 0;
        for(auto &u : G[ans[i-1]]){
            if(ans[i] == u){
                curr = 1;
            }
        }
        if(!curr){
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
    for(auto &i : ans) cout << i+1 << " ";
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}