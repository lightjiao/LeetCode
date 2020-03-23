/**
给定一个按照升序排列的整数数组 nums，和一个目标值
target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
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
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        int targetPos = -1;
        while (l <= r) {
            // 右移 等同于除以2
            mid = (l + r) >> 1;

            if (nums[mid] == target) {
                targetPos = mid;
                break;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
                continue;
            }
            else {
                l = mid + 1;
                continue;
            }
        }

        if (targetPos == -1) {
            return vector<int>{-1, -1};
        }
        else {
            int l = targetPos, r = targetPos;

            while (l > 0 && nums[l - 1] == target) {
                l--;
            }
            while (r < nums.size() - 1 && nums[r + 1] == target) {
                r++;
            }

            return vector<int>{l, r};
        }
    }
};

TEST_CASE("test")
{
    Solution    s;
    vector<int> nums;
    vector<int> expect;

    nums   = {5, 7, 7, 8, 8, 10};
    expect = {3, 4};
    REQUIRE(s.searchRange(nums, 8) == expect);

    nums   = {5, 7, 7, 8, 8, 10};
    expect = {-1, -1};
    REQUIRE(s.searchRange(nums, 6) == expect);
}
