// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

#include <iostream>
#include <vector>
#include <climits>
#include <stdexcept> // For invalid_argument

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is smaller
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m, medianPos = (m + n + 1) / 2;

        while (left <= right)
        {
            int partition1 = (left + right) / 2;
            int partition2 = medianPos - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                // Found correct partition
                if ((m + n) % 2 == 0)
                {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
                else
                {
                    return max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2)
            {
                right = partition1 - 1; // Move left
            }
            else
            {
                left = partition1 + 1; // Move right
            }
        }

        throw invalid_argument("Input arrays are not sorted!");
    }
};

// ✅ Add the missing `main()` function
int main()
{
    Solution sol;

    // Example Test Cases
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl; // Expected: 2.00000

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Median: " << sol.findMedianSortedArrays(nums3, nums4) << endl; // Expected: 2.50000

    return 0;
}
