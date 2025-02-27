#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void backtrack(int openCount, int closeCount, int n, string current, vector<string> &result)
    {
        if (current.length() == 2 * n)
        {
            result.push_back(current);
            return;
        }

        if (openCount < n)
        {
            backtrack(openCount + 1, closeCount, n, current + "(", result);
        }

        if (closeCount < openCount)
        {
            backtrack(openCount, closeCount + 1, n, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(0, 0, n, "", result);
        return result;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<string> result = sol.generateParenthesis(n);

    cout << "Generated Parentheses for n = " << n << ":\n";
    for (const string &s : result)
    {
        cout << s << endl;
    }

    return 0;
}
