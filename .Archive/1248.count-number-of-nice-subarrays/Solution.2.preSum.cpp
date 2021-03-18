#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
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
     * 前缀和
     */
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        int n      = nums.size();
        int oddCnt = 0, result = 0;

        /**
         * 首先：
         * 前缀和数组：prefix[i] 代表下标 i 之前有多少个奇数
         * 那么会有这样一个式子：prefix[i] - prefix[j - 1] == k
         * 我们计算出这个式子成立的个数即可，但复杂度是 O(n2)
         * 
         * 对上面式子换一个写法就是 prefix[j - 1] = prefix[i] - k
         *
         * prefixCnt 不是单纯的前缀和数组
         * 这个数组的意义是用HashMap的形式优化前缀和的计算
         * 下标是前缀和，值是前缀和的个数
         * 因此，遍历原数组，每遍历一个元素计算当前前缀和 oddCnt
         * 在 result 中累加前缀和为 oddCnt - k 的个数
         */
        vector<int> prefixCnt(n + 1, 0);

        prefixCnt[0] = 1;  // ??
        for (int i = 0; i < n; i++)
        {
            oddCnt += (nums[i] & 1);
            prefixCnt[oddCnt] += 1;

            result += oddCnt >= k ? prefixCnt[oddCnt - k] : 0;
        }
        return result;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<int> param;

    param = {1, 1, 2, 1, 1};
    REQUIRE(s.numberOfSubarrays(param, 3) == 2);

    param = {2, 4, 6};
    REQUIRE(s.numberOfSubarrays(param, 1) == 0);

    param = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    REQUIRE(s.numberOfSubarrays(param, 2) == 16);

    param = {3, 8, 0, 1, 8, 3, 0, 2, 2, 8, 8, 3, 1, 1};
    REQUIRE(s.numberOfSubarrays(param, 4) == 6);

    param = {91473, 45388, 24720, 35841, 29648, 77363, 86290,
             58032, 53752, 87188, 34428, 85343, 19801, 73201};
    REQUIRE(s.numberOfSubarrays(param, 4) == 6);
};
