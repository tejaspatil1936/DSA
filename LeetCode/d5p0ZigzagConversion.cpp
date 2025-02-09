#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.length() <= numRows)
            return s;

        vector<string> rows(min(numRows, (int)s.length()));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string &row : rows)
        {
            result += row;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s;
    int numRows;

    cout << "Enter string: ";
    cin >> s;
    cout << "Enter number of rows: ";
    cin >> numRows;

    cout << "Zigzag Conversion: " << sol.convert(s, numRows) << endl;
    return 0;
}
