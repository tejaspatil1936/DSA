#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return (x == reversedHalf || x == reversedHalf / 10);
    }
};

int main() {
    Solution sol;
    int testCases[] = {121, -121, 10, 12321, 0, 1221, 1001, 123};

    for (int x : testCases) {
        cout << "Input: " << x << " -> Output: " << (sol.isPalindrome(x) ? "true" : "false") << endl;
    }

    return 0;
}
