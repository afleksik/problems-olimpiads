#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> x;
        arr[i] = x;
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}