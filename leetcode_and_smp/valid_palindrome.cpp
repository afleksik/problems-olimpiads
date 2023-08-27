#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

// https://leetcode.com/problems/valid-palindrome/description/

bool isPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;
    while (start < end) {
        while (start < end && !isalnum(s[start])) {
            start++;
        }
        while (start < end && !isalnum(s[end])) {
            end--;
        }
        if(start < end && tolower(s[start]) != tolower(s[end])) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    cout << isPalindrome("aboba");
    return 0;
}