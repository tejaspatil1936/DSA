#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ')
            i++;

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long num = 0;
        while (i < n && isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
            if (sign * num <= INT_MIN)
                return INT_MIN;
            if (sign * num >= INT_MAX)
                return INT_MAX;
            i++;
        }

        return sign * num;
    }
};

int main()
{
    Solution sol;
    cout << sol.myAtoi("42") << endl;
    cout << sol.myAtoi("   -42") << endl;
    cout << sol.myAtoi("4193 with words") << endl;
    cout << sol.myAtoi("words and 987") << endl;
    cout << sol.myAtoi("-91283472332") << endl;
    return 0;
}
