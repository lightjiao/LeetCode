/**
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.h"
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 遍历 再 二分查找
     */
    int search(vector<int>& nums, int target)
    {
        if (nums.size() == 0) {
            return -1;
        }

        int rotatedIdx = findRotatedIndex(nums);

        if (target == nums[0]) {
            return 0;
        }
        else if (target > nums[0]) {
            return _search(nums, 0, rotatedIdx - 1, target);
        }
        else {
            return _search(nums, rotatedIdx, nums.size() - 1, target);
        }
    }

    int _search(vector<int>& nums, int l, int r, int target)
    {
        if (l > r) {
            return -1;
        }

        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            return _search(nums, l, mid - 1, target);
        }
        else {
            return _search(nums, mid + 1, r, target);
        }
    }

    int findRotatedIndex(vector<int>& nums)
    {
        int rotatedIdx = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                continue;
            }

            if (nums[i] < nums[i - 1]) {
                rotatedIdx = i;
                break;
            }
        }

        return rotatedIdx;
    }
};

TEST_CASE("test")
{
    Solution    s;
    vector<int> nums;

    nums = {5, 1, 3};
    REQUIRE(s.search(nums, 3) == 2);

    nums = {1, 3};
    REQUIRE(s.search(nums, 3) == 1);

    nums = {4, 5, 6, 7, 0, 1, 2};
    REQUIRE(s.search(nums, 0) == 4);

    nums = {4, 5, 6, 7, 0, 1, 2};
    REQUIRE(s.search(nums, 3) == -1);

    nums = {3, 1};
    REQUIRE(s.search(nums, 3) == 0);
}
