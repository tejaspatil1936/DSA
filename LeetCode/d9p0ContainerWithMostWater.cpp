#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            maxWater = max(maxWater, area);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxWater;
    }
};

// Driver Code
int main()
{
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Maximum Water: " << sol.maxArea(height) << endl;

    return 0;
}
