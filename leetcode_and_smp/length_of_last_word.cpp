#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/length-of-last-word/description/
int lengthOfLastWord(string s) {
    int flag = 0;
    int size = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ' ' && flag == 1) {
            break;
        }
        if (s[i] != ' ') {
            flag = 1;
            size++;
        }
    }
    return size;
}