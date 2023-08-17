/*
 Дан неориентированный граф из N вершин и M ребер. Необходимо проверить, 
 является ли граф деревом. Дерево — это связный граф без циклов.
 Формат ввода
 
 Во входном файле в первой строке содержатся два целых числа N и M (1 ≤ N ≤ 100, 1 ≤ M ≤ 1000),
 записанные через пробел.
 
 Далее следуют M различных строк с описаниями ребер, каждая из которых содержит 
 два натуральных числа Ai и Bi (1 ≤ Ai ≤ Bi ≤ N), где Ai и Bi — номера вершин, соединенных i-м ребром.

Формат вывода
 В выходной файл выведите слово «YES», если граф является деревом, или «NO» в противном случае.

Пример 1
Ввод


3 2
1 2
1 3

	
Вывод
YES


*/


#include <bits/stdc++.h> 

using namespace std;

const int maxg = 100000;
vector<int> graph[maxg];
bool used[maxg];

void dfs(int v, int *arr, int comp) {
    used[v] = true;
    arr[v] = comp;
    for (int u : graph[v]) {
        if (!used[u]) {
            dfs(u, arr, comp);
        }
    }
}

int main() {
    int m, u_i, v_i, n;
    int count = 0;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < m; ++i){
        cin >> u_i >> v_i;
        graph[u_i].push_back(v_i);
        graph[v_i].push_back(u_i);
    }
    int j = 1;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            count++;
            dfs(i, arr, j);
            ++j;
        }
    }

    if ((n == m + 1) && (count == 1)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}