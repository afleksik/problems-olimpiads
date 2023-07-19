#include <iostream>
#include <vector>

using namespace std;

int count(vector<int> ar, int n, int target){
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if (ar[i] == target){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n = 0;
    int col;
    int m;
    int req;
    vector<int> col_ar;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> col;
        col_ar.push_back(col);
    }
    cin >> m;
    for (int j = 0; j < m; ++j){
        cin >> req;
        cout << count(col_ar, n, req) << "\n";
    }
    return 0;
}