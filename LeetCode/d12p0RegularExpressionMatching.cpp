#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution solution;

    string s1 = "aa", p1 = "a";
    string s2 = "aa", p2 = "a*";
    string s3 = "ab", p3 = ".*";
    string s4 = "mississippi", p4 = "mis*is*p*.";

    cout << boolalpha;
    cout << "Test 1: " << solution.isMatch(s1, p1) << endl;
    cout << "Test 2: " << solution.isMatch(s2, p2) << endl;
    cout << "Test 3: " << solution.isMatch(s3, p3) << endl;
    cout << "Test 4: " << solution.isMatch(s4, p4) << endl;

    return 0;
}
