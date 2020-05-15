/**
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file

#include "../ListNode.cpp"
// #include "../MyPriorityQueue.cpp"
#include "../TreeNode.cpp"
#include "../VV.cpp"
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 前缀和 + 哈希优化
     */
    int subarraySum(vector<int>& nums, int k)
    {
        // preSum, count
        map<int, int> preSumCount;
        preSumCount[0] = 1;

        int result = 0;
        int preSum = 0;
        for (auto&& n : nums)
        {
            preSum += n;

            if (preSumCount.find(preSum - k) != preSumCount.end())
            {
                result += preSumCount[preSum - k];
            }

            preSumCount[preSum]++;
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution    s;
    vector<int> nums;

    nums = {1, 1, 1};
    REQUIRE(s.subarraySum(nums, 2) == 2);

    nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    REQUIRE(s.subarraySum(nums, 0) == 55);

    nums = {8, -3, 7, -4, 8, -2, 3, -6, 1, -2, 8, 7, -4, 0, 6, -1, 2, -8, 5, 0};
    REQUIRE(s.subarraySum(nums, 5) == 9);
}
