#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long max_wide(long long n, long long a, long long b, long long w, long long h) {
    long long l = 0, r, mid, x;
    r = min(w, h);    

    while (r - l > 1) {
        mid = (l + r) / 2;
        x = (w / (a + 2 * mid)) * (h / (b + 2 * mid));
        if (x >= n) {
            l = mid;
        }
        else {
            r  = mid;
        }
    }

    return l;
}

int main() {
    long long n, a, b, w, h, x1, x2;
    
    cin >> n >> a >> b >> w >> h;
    
    x1 = max_wide(n, a, b, w, h);
    x2 = max_wide(n, b, a, w, h);

    cout << max(x1, x2);
    
    return 0;
}