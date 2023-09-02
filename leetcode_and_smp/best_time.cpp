#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

int maxProfit(vector<int>& prices) {
    int max_prof = 0, min_p = 10000;
    for (auto to : prices) {
        min_p = min(min_p, to);
        max_prof = max(to - min_p, max_prof);
    }
    return max_prof;
}   

int main() {
    int size = 0;
    cin >> size;
    vector<int> prices(size, 0);

    for (int i = 0; i < size; ++i) {
        cin >> prices[i];
    }

    cout << maxProfit(prices);
}