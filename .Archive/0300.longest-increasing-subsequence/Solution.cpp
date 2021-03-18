/**
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 动态规划
     */
    int lengthOfLIS(vector<int> nums)
    {
        if (nums.size() == 0) {
            return 0;
        }

        /**
         * 保存以字符串i 结尾的字符串中最长的子串长度
         * dp[i+1] = max( nums[0]...nums[i-1] 中比nums[i]小的i -> dp[i] ) + 1
         * 换一种写法: dp[i] = max(dp[i], dp[j] + 1) for j in [0, i)
         */
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

TEST_CASE("test")
{
    Solution s;
    REQUIRE(s.lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    REQUIRE(s.lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18, 19}) == 5);
    REQUIRE(s.lengthOfLIS({}) == 0);
}
