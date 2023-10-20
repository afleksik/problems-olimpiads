#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/

int countGoodSubstrings(string s) {
        int n = s.size();
        int count = 0;
        string cur_s;

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i; j < i + 3; ++j) {
                cur_s += s[j];
            }
            cout << cur_s << "\n";
            if (isgood(cur_s)) {
                count++;
            }
            cur_s = "";
        }
        return count;
    }

    bool isgood(string s) {
        for (int i = 0; i < s.size() - 1; ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    return false;
                }
            }
        }
        return true;
    }