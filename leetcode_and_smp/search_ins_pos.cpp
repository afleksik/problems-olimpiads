#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int mid = 0;
    if (target > nums[r - 1]) {
        return r;
    }

    while (l <= r) {
        mid = (r + l) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            l = mid + 1;
        }
        else {
            return r = mid - 1;
        }
    }
    return l;
} // 44/65 testcases passed

int main() {
    int target, size;
    cin >> size >> target;
    vector<int> ar(size);
    
    for (int i = 0; i < size; ++i) {
        cin >> ar[i];
    }

    cout << searchInsert(ar, target);

    return 0;
}