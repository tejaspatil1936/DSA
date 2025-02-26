#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(int openCount, int closeCount, int n, string current, vector<string>& result) {
        // Base case: If the length of the current string is 2*n, add to result
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we haven't used all 'n' open parentheses
        if (openCount < n) {
            backtrack(openCount + 1, closeCount, n, current + "(", result);
        }

        // Add ')' if closeCount is less than openCount
        if (closeCount < openCount) {
            backtrack(openCount, closeCount + 1, n, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, n, "", result);
        return result;
    }
};

// **Driver Code**
int main() {
    Solution sol;
    int n = 3;
    vector<string> result = sol.generateParenthesis(n);

    cout << "Generated Parentheses for n = " << n << ":\n";
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
