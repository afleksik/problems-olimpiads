#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, 0);
        auto first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        auto last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }
        res.emplace_back(first);
        res.emplace_back(last - 1);
        return res;
}

int main() {


}