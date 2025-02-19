#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = sol.threeSum(nums1);
    cout << "Example 1:" << endl;
    for (const auto &triplet : result1)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> result2 = sol.threeSum(nums2);
    cout << "Example 2:" << endl;
    for (const auto &triplet : result2)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    cout << endl;

    // Example 3
    vector<int> nums3 = {0, 0, 0, 0};
    vector<vector<int>> result3 = sol.threeSum(nums3);
    cout << "Example 3:" << endl;
    for (const auto &triplet : result3)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    cout << endl;

    // Example 4 (Empty input)
    vector<int> nums4 = {};
    vector<vector<int>> result4 = sol.threeSum(nums4);
    cout << "Example 4 (Empty input):" << endl;
    for (const auto &triplet : result4)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    cout << endl;

    return 0;
}
