/*

 
 Реализуйте эффективную структуру данных, позволяющую изменять элементы массива и
 вычислять суммы нескольких подряд идущих элементов.

Формат ввода
 В первой строке вводится одно натуральное число N (1 ≤ N ≤ 100000) — количество чисел в массиве.
 Во второй строке вводятся N чисел от 0 до 100000 — элементы массива.
 В третьей строке вводится одно натуральное число M (1 ≤ M ≤ 30000) — количество запросов.
 Каждая из следующих M строк представляет собой описание запроса. 
 Сначала вводится одна буква, кодирующая вид запроса (s — вычислить сумму, u — обновить значение элемента).
 Следом за s вводятся два числа — номера левой и правой границы отрезка.
 Следом за u вводятся два числа — номер элемента и его новое значение.

Формат вывода
Для каждого запроса s выведите результат. Все числа выводите в одну строку через пробел.

Пример
Ввод
10
613 263 312 670 216 142 976 355 488 370
10
s 2 7
s 4 8
u 7 969
u 1 558
s 2 7
u 2 731
s 4 9
s 1 3
u 8 76
u 5 377
	
Вывод
2579 2359 2572 2840 1601 


*/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct SegmentTree {
    ll size;
    vector<ll> tree;
    SegmentTree(vector<ll> &a) {
        size = a.size();
        tree.assign(4*size, 0);
        build(a, 0, 0, size);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            // лист
            tree[x] = a[lx];
            return ;
        }
        ll mx = (lx + rx) / 2;
        build(a, 2*x + 1, lx, mx);
        build(a, 2*x + 2, mx, rx);
        tree[x] = tree[2*x + 1] + tree[2*x + 2];
    }

    ll get(ll l, ll r, ll x, ll lx, ll rx) {
        if (l <= lx && rx <= r) {
            return tree[x];
        }

        if (r <= lx || rx <= l) {
            return 0;
        }

        ll mx = (rx + lx) / 2;

        return get(l, r, 2*x + 1, lx, mx) + get(l, r, 2*x + 2, mx, rx);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }

        ll mx = (lx + rx) / 2;

        if (i < mx) {
            set(i, v, 2*x + 1, lx, mx);
        }
        else {
            set(i, v, 2*x + 2, mx, rx);
        }

        tree[x] = tree[2*x + 1] + tree[2 * x + 2];
    }

    ll get(ll l, ll r) {
        return get(l, r, 0, 0, size);
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }
};

int main() {
    ll n, m;
    cin >> n;

    vector <ll> a(n, 0);
    vector <ll> ans;

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;
    
    SegmentTree st(a);
    for (ll i = 0; i < m; ++i){
        string t;
        ll l, r, x, id;

        cin >> t;
        
        if (t == "u"){
            cin >> id >> x;
            st.set(id - 1, x);
        }
        
        else if (t == "s"){
            cin >> l >> r;
            --l;
            --r;
            ans.push_back(st.get(l, r + 1));
        }
    }
 
    for (auto c : ans){
        cout << c << " ";
    }
}