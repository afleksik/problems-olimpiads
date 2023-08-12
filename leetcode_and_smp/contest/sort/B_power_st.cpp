#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, x, d, j = 1;
    int min_id = 0;
    cin >> n;

    vector<int> stations_cpy(n, 0);
    vector<int> stations(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> x;
        stations[i] = x;
        stations_cpy[i] = x;
    }

    sort(stations.begin(), stations.end());

    for (int i = 0; i < n - 2; ++i) {
        d = stations[j] - stations[i];
        if (stations[j + 1] - stations[i + 1] < d) {
            min_id = i;
        }
        ++j;
    }

    for (int i = 0; i < n; ++i) {
        if (stations_cpy[i] == stations[min_id]) {
            cout << i + 1;
        }
    }

    return 0;
}