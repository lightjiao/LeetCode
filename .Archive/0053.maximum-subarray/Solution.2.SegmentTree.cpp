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
     * 分治：基于线段树的分治
     * 链接：https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/
     */
    int maxSubArray(vector<int>& nums)
    {
        return get(nums, 0, nums.size() - 1).mSum;
    }

    struct Status
    {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r)
    {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max({l.rSum + r.lSum, l.mSum, r.mSum});
        return Status{lSum, rSum, mSum, iSum};
    }

    Status get(vector<int>& a, int l, int r)
    {
        if (l == r)
        {
            return Status{a[l], a[l], a[l], a[l]};
        }

        int    m    = (l + r) >> 1;  //(l+r)/2
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);

        return pushUp(lSub, rSub);
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
