/*
 Дан ориентированный невзвешенный граф. Необходимо его топологически отсортировать.

Формат ввода
 В первой строке входного файла даны два натуральных числа N и M 
 (1≤N≤100000,M≤1000001≤N≤100000,M≤100000) количество вершин и рёбер в графе соответственно.
 Далее в MM строках перечислены рёбра графа. Каждое ребро задаётся парой чисел – номерами
 начальной и конечной вершин соответственно.

Формат вывода
 Вывести любую топологическую сортировку графа в виде последовательности номеров вершин. 
 Если граф невозможно топологически отсортировать, вывести −1.

Пример
Ввод

6 6
1 2
3 2
4 2
2 5
6 5
4 6

	
Вывод
4 6 3 1 2 5 

*/

#include <bits/stdc++.h> 

using namespace std;

const int maxg = 1e5;
vector<int> graph[maxg];
vector<int> used(maxg);
vector<int> s;
bool flag = false;

void dfs(int v) {
    used[v] = 1;
    for (int u : graph[v]) {
        if (used[u] == 1) {
            flag = true;
        }
        if (used[u] == 0) {
            dfs(u);
        }
    }
    used[v] = 2;
    s.push_back(v);
}

int main() {
    int n, m, u_i, v_i;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u_i >> v_i;
        graph[u_i].push_back(v_i);
    }

    for (int i = 0; i <= n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    if (flag){
        cout << -1;
    }
    else {
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size() - 1; ++i) {
            cout << s[i] << " ";
        }
    }
}