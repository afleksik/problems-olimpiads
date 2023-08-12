#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int x, i, j;
    int m = 0, n = 0;
    cin >> x;
    vector<int> a(x + 1, 0);
    vector<int> b(x + 1, 0);
    vector<int> c(x + 1, 0);

    for (int i = 1; i < x + 1; ++i) {
        a[i] = i * i;
        b[i] = i * i * i;
    }
    for (int i = 0; i < x + 1; ++i) {
        if (a[m] < b[n]) {
            c[i] = a[m];
            ++m;
        }
        else if (b[n] < a[m]) {
            c[i] = b[n];
            ++n;
        }
        else {
            c[i] = a[m];
            ++m;
            ++n;
        }
    }
    cout << c[x];
    return 0;
} 