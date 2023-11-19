#include <bits/stdc++.h>

using namespace std;

#pragma  GCC optimize("O2")
#define ll long long

const int INF = 1e9;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;

    vector<ll> mas(n);

    ll new_size = n - 1;
    ll f_min = INF;

    for (int i = 0; i < n; i++) {
        cin >> mas[i];
        f_min = min(f_min, mas[i]);
    }

    cout << f_min << " ";
    int count = 1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - count; j++) {
            mas[j] = max(mas[j], mas[j + 1]);
        }
        mas.resize(n - count);
        ll f_min = INF;
        for (int j = 0; j < n-count; j++) {
            f_min = min(mas[j], f_min);
        }
        cout << f_min << " ";
        count++;
    }

}