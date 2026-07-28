#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (isOpen(c)) {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    if (c == ')' && st.top() != '(')
                        return false;
                    if (c == ']' && st.top() != '[')
                        return false;
                    if (c == '}' && st.top() != '{')
                        return false;
                    st.pop();
                }
            }
        }
        return st.empty();
    }

    bool isOpen(char c){
        return c == '(' || c == '[' || c == '{';
    }
};