#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    long long a, b;
    long long x, y;
    long long mid = 0, value_d = 0, value_m = 0;
    cin >> a >> b;
    cin >> x >> y;
    
    mid = a;
    value_d = mid * x;
    value_m = (a + b - mid) * y;

    if (value_d < value_m) {
        long long steps = (value_m - value_d) / (2 * y);
        if ((value_m - value_d) % (2 * y) > y) {
            cout << mid + steps + 1;
        }
        else {
            cout << mid + steps;
        }
    }
    else {
        long long steps = (value_d - value_m) / (2 * x);
        if ((value_d - value_m) % (2 * x) > x) {
            cout << mid - steps - 1;
        }
        else {
            cout << mid - steps;
        }
    }

    return 0;
}