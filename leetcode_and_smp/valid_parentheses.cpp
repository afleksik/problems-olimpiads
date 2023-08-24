#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
    stack<char> st;  
    for (int i = 0; i < s.size(); ++i) {
        char symb = s[i];
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if (!st.empty()) {
                if ((st.top() == '(' && symb == ')') || (st.top() == '{' && symb == '}') || (st.top() == '[' && symb == ']')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    if (st.empty()) {
        return true;
    }
    else {
        return false;
    }
    }
};