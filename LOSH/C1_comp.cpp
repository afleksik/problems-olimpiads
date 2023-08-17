/*
 Дан неориентированный невзвешенный граф. Необходимо посчитать 
 количество его компонент связности и вывести их.
 
Формат ввода
 Во входном файле записано два числа N и M (0 < N <= 100000, 0 <= M <= 100000).
 В следующих M строках записаны по два числа i и j (1 <= i, j <= N), 
 которые означают, что вершины i и j соединены ребром.

Формат вывода
 В первой строчке выходного файла выведите количество компонент связности. 
 Далее выведите N целых чисел, i-е из них задаёт номер компоненты связности для i-й вершины.
 Компоненты следует нумеровать последовательными целыми числами от 1. 
 Порядок нумерации компонент произвольный.

Пример
Ввод


4 2
1 2
3 4

	
Вывод
2
1 1 2 2 


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

    cout << count << "\n";
    for (int i = 1; i < n + 1; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}