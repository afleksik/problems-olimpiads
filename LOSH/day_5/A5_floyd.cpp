#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j]; 
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " "; 
        }
        cout << "\n";
    }
}