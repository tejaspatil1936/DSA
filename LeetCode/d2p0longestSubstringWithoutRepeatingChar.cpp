#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_set<char> charSet;
        int start = 0;
        int maxLength = 0;

        for (int end = 0; end < s.size(); ++end)
        {
            while (charSet.count(s[end]))
            {
                charSet.erase(s[start]);
                start += 1;
            }

            charSet.insert(s[end]);
            maxLength = std::max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};

int main()
{
    Solution sol;
    std::string s = "abcabcbb";
    int length = sol.lengthOfLongestSubstring(s);
    std::cout << "Length of longest substring: " << length << std::endl;

    return 0;
}
