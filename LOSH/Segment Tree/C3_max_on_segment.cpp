/*


Реализуйте структуру данных для эффективного вычисления максимумов подряд идущих элементов массива.
Формат ввода

В первой строке вводится одно натуральное число N (1 ≤ N ≤ 100000) — количество чисел в массиве.

Во второй строке вводятся N чисел от 1 до 100000 — элементы массива.

В третьей строке вводится одно натуральное число K (1 ≤ K ≤ 30000) — 
количество запросов на вычисление максимума.

В следующих K строках вводится по два числа — номера левого и правого элементов отрезка 
массива (считается, что элементы массива нумеруются с единицы).
Формат вывода

Для каждого запроса выведите значение максимального элемента на указанном отрезке массива. 
Числа выводите в одну строку через пробел.
Пример 1
Ввод


5
2 2 2 1 5
2
2 3
2 5

	
Вывод
2 5

Пример 2
Ввод


10
18 16 20 2 53 57 39 97 21 59
10
3 10
1 10
3 4
9 10
8 10
5 8
6 7
5 8
1 10
7 9

	
Вывод
97 97 20 59 97 97 57 97 97 97

*/


#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Node {
    ll mx{};
    ll cnt{};
};

Node combine(Node a, Node b) {
    if (a.mx > b.mx) {
        return a;
    }
    if (a.mx < b.mx) {
        return b;
    }

    return {a.mx, a.cnt + b.cnt};
}

struct SegmentTree {
    ll size;
    vector<Node> tree;
    SegmentTree(vector<ll> &a) {
        size = a.size();
        tree.assign(4 * size, Node());
        build(a, 0, 0, size);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = {a[lx], 1};
            return ;
        }
        ll mx = (lx + rx) / 2;
        build(a, 2*x + 1, lx, mx);
        build(a, 2*x + 2, mx, rx);
        tree[x] = combine(tree[2*x + 1], tree[2*x + 2]);
    }

    Node get(ll l, ll r, ll x, ll lx, ll rx) {
        if (l <= lx && rx <= r) {
            return tree[x];
        }

        if (r <= lx || rx <= l) {
            return {};
        }

        ll mx = (rx + lx) / 2;

        return combine(get(l, r, 2*x + 1, lx, mx), get(l, r, 2*x + 2, mx, rx));
    }

    Node get(ll l, ll r) {
        return get(l, r, 0, 0, size);
    }
};

int main() {
    ll n, k, l, r;

    vector<Node> ans;

    cin >> n;
    vector<ll> mas(n, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> mas[i];
    }

    cin >> k;
    SegmentTree st(mas);

    for (ll i = 0; i < k; ++i) {
        cin >> l >> r;
        --l;
        --r;
        ans.push_back(st.get(l, r + 1));
        cout << ans[i].mx << " ";
    }
}