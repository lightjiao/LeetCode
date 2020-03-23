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
        vector<int> result{-1, -1};

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target) {
                break;
            }

            if (nums[i] == target) {
                if (result[0] == -1) {
                    result[0] = i;
                }
                result[1] = i;
            }
        }

        return result;
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
