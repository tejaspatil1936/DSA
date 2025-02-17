#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        sort(strs.begin(), strs.end()); // Sort the array
        
        string first = strs[0];
        string last = strs[strs.size() - 1];
        int i = 0;
        
        while (i < first.size() && first[i] == last[i]) {
            i++;
        }
        
        return first.substr(0, i);
    }
};

int main() {
    Solution sol;
    vector<vector<string>> testCases = {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"apple", "ape", "april"},
        {"",""},
        {"a"}
    };
    
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        cout << sol.longestCommonPrefix(testCases[i]) << endl;
    }

    return 0;
}
