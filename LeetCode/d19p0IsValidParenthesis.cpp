#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if ((c == ')' && top != '(') || 
                    (c == '}' && top != '{') || 
                    (c == ']' && top != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    cout << sol.isValid("()") << endl;      // Output: 1 (true)
    cout << sol.isValid("()[]{}") << endl;  // Output: 1 (true)
    cout << sol.isValid("(]") << endl;      // Output: 0 (false)
    cout << sol.isValid("([)]") << endl;    // Output: 0 (false)
    return 0;
}
