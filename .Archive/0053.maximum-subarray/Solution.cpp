/**
给定一个整数数组
nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
#include "../VV.cpp"
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * DP
     * 记录以i为结尾的子数组的最大和
     */
    int maxSubArray(vector<int>& nums)
    {
        if (nums.size() == 0) {
            return 0;
        }

        int dp     = nums[0];
        int result = dp;
        for (int i = 1; i < nums.size(); i++) {
            dp     = max(nums[i], nums[i] + dp);
            result = max(result, dp);
        }
        return result;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<int> param;

    param = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    REQUIRE(s.maxSubArray(param) == 6);

    param = {1};
    REQUIRE(s.maxSubArray(param) == 1);
}
