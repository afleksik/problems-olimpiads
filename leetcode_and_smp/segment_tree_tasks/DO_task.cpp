#include <bits/stdc++.h>

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


//int main() {
//    int k = 0, xi = 0, yi = 0;
//    cin >> k;
//
//    vector <ll> a;
//    for (ll i = 0; i < 100000; ++i) {
//        a[i] = i * i % 12345 + i * i * i % 23456;
//    }
//    
//    SegmentTree st(a);
//
//    for (ll i = 0; i < k; ++i){
//        cin >> xi >> yi;
//
//        if (xi > 0) {
//            cout << st.get(xi, yi);
//        }
//        else if (xi < 0) {
//            st.set(xi - 1, yi);
//        }
//    }
//
//    return 0;
//}