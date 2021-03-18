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

        int nums1LeftPos = 0, nums2LeftPos = 0;
        int nums1RightPos = nums1.size() - 1, nums2RightPos = nums2.size() - 1;

        int leftNum = 0;
        int rightNum = 0;

        int nums1LeftNumber = 0, nums2LeftNumber = 0;
        int nums1RightNumber = 0, nums2RightNumber = 0;
        do
        {
            nums1LeftNumber = nums1LeftPos < nums1.size() ? nums1[nums1LeftPos] : numeric_limits<int>::max();
            nums2LeftNumber = nums2LeftPos < nums2.size() ? nums2[nums2LeftPos] : numeric_limits<int>::max();

            nums1RightNumber = nums1RightPos >= 0 ? nums1[nums1RightPos] : numeric_limits<int>::min();
            nums2RightNumber = nums2RightPos >= 0 ? nums2[nums2RightPos] : numeric_limits<int>::min();

            if (nums1LeftNumber < nums2LeftNumber)
            {
                leftNum = nums1LeftNumber;
                nums1LeftPos++;
            }
            else
            {
                leftNum = nums2LeftNumber;
                nums2LeftPos++;
            }

            if (nums1RightNumber > nums2RightNumber)
            {
                rightNum = nums1RightNumber;
                nums1RightPos--;
            }
            else
            {
                rightNum = nums2RightNumber;
                nums2RightPos--;
            }

        } while (leftNum < rightNum);

        return (leftNum + rightNum) / 2.0;
    }
};