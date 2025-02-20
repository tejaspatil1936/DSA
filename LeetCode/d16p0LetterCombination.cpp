#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        string current;
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(digits, mapping, 0, current, result);
        return result;
    }

private:
    void backtrack(const string &digits, const vector<string> &mapping, int index, string &current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, mapping, index + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    string digits = "23";
    vector<string> combinations = sol.letterCombinations(digits);

    for (const string &comb : combinations) {
        cout << comb << " ";
    }
    return 0;
}
