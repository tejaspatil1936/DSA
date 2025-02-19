#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

class Solution
{
public:
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        int closestSum = std::numeric_limits<int>::max();

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (std::abs(currentSum - target) < std::abs(closestSum - target))
                {
                    closestSum = currentSum;
                }

                if (currentSum < target)
                {
                    left++;
                }
                else if (currentSum > target)
                {
                    right--;
                }
                else
                {
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};

int main()
{
    Solution sol;

    // Example 1
    std::vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    std::cout << "Example 1: " << sol.threeSumClosest(nums1, target1) << std::endl; // Expected Output: 2

    // Example 2
    std::vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    std::cout << "Example 2: " << sol.threeSumClosest(nums2, target2) << std::endl; // Expected Output: 0

    // Example 3
    std::vector<int> nums3 = {1, 1, 1, 0};
    int target3 = -100;
    std::cout << "Example 3: " << sol.threeSumClosest(nums3, target3) << std::endl; // Expected Output: 2

    // Example 4
    std::vector<int> nums4 = {1, 1, -1, -1, 3};
    int target4 = -1;
    std::cout << "Example 4: " << sol.threeSumClosest(nums4, target4) << std::endl; // Expected Output: -1

    return 0;
}
