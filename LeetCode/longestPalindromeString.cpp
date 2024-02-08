// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
#include <iostream>
#include <string>  // ✅ Add this header

using namespace std;  // ✅ Add this to use `string` without `std::`

class Solution {
public:
    string longestPalindrome(string s) {  // ✅ Now `string` will be recognized
        if (s.empty()) return "";
        
        int start = 0, maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, start, maxLen);    // Expand for odd-length palindrome
            expand(s, i, i + 1, start, maxLen); // Expand for even-length palindrome
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    void expand(string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > maxLen) {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    return 0;
}
