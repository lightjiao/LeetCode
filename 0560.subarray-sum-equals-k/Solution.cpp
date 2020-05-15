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
     * 暴力梭哈
     */
    int subarraySum(vector<int>& nums, int k)
    {
        fminZeroSubarrayIndex(nums);

        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    result++;
                    int subarrayTail = j + 1;
                    while (minZeroSubarrayIndex.find(subarrayTail) !=
                           minZeroSubarrayIndex.end())
                    {
                        result++;
                        subarrayTail = minZeroSubarrayIndex[subarrayTail] + 1;
                    }

                    break;
                }
            }
        }

        return result;
    }

    // 找出所有和为0的最小子数组
    map<int, int> minZeroSubarrayIndex;

    void fminZeroSubarrayIndex(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == 0)
                {
                    minZeroSubarrayIndex[i] = j;
                    break;
                }
            }
        }

        return;
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
