/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int No1 = (nums1.size() + nums2.size() + 1) / 2;
        int No2 = (nums1.size() + nums2.size() + 2) / 2;

        vector<int> nums1Range = {0, (int)nums1.size() - 1};
        vector<int> nums2Range = {0, (int)nums2.size() - 1};

        int num1 = findXthInArrays(nums1, nums1Range, nums2, nums2Range, No1);
        int num2 = findXthInArrays(nums1, nums1Range, nums2, nums2Range, No2);

        return (num1 + num2) / 2.0;
    }

private:
    int findXthInArrays(vector<int> &nums1, vector<int> nums1Range, vector<int> &nums2, vector<int> nums2Range, int No)
    {
        int length1 = nums1Range[1] - nums1Range[0] + 1;
        int length2 = nums2Range[1] - nums2Range[0] + 1;

        // 确保只处理一个length的边界
        if (length1 > length2)
        {
            return findXthInArrays(nums2, nums2Range, nums1, nums1Range, No);
        }

        if (length1 == 0)
        {
            return nums2[nums2Range[0] + No - 1];
        }

        if (No == 1)
        {
            return min(nums1[nums1Range[0]], nums2[nums2Range[0]]);
        }

        int i = nums1Range[0] + min(length1, No / 2) - 1;
        int j = nums2Range[0] + min(length2, No / 2) - 1;

        if (nums1[i] < nums2[j])
        {
            No = No - (i - nums1Range[0] + 1);
            nums1Range[0] = i + 1;
        }
        else
        {
            No = No - (j - nums2Range[0] + 1);
            nums2Range[0] = j + 1;
        }

        return findXthInArrays(nums1, nums1Range, nums2, nums2Range, No);
    }
};