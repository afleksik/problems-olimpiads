#include <iostream>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    if (k == 1) {
        cout << 0;
    }
    else if(m < k) {
        cout << ((n - 1) * m) + ((m - 1) * n);
    }
    else {
        cout << (m - 1) * n;
    }

    return 0;
}