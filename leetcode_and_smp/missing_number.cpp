#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    short int l = 0;
    short int r = nums.size() - 1;
    short int mid = 0;
    short int res = 0;

    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == mid) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    
    return l;
}