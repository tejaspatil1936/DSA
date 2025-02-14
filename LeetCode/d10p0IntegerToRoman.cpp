#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string intToRoman(int num)
    {
        std::vector<std::pair<int, std::string>> valueSymbol = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        std::string result;

        for (const auto &[value, symbol] : valueSymbol)
        {
            while (num >= value)
            {
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    int num = 3749;
    std::string romanNumeral = solution.intToRoman(num);
    std::cout << romanNumeral << std::endl;
    return 0;
}
