#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void computeLPS(string &needle, vector<int> &lps)
    {
        int m = needle.size(), len = 0;
        lps[0] = 0;
        int i = 1;

        while (i < m)
        {
            if (needle[i] == needle[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        if (m == 0)
            return 0;

        vector<int> lps(m, 0);
        computeLPS(needle, lps);

        int i = 0, j = 0;
        while (i < n)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == m)
                return i - j;
            if (i < n && haystack[i] != needle[j])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    string haystack = "sadbutsad", needle = "sad";
    cout << "Output: " << sol.strStr(haystack, needle) << endl; // Expected Output: 0
    return 0;
}
