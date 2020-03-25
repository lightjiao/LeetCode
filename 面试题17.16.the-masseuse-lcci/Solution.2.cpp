/**
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。
给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

注意：本题相对原题稍作改动

示例 1：
输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。

示例 2：
输入： [2,7,9,3,1]
输出： 12
解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。

示例 3：
输入： [2,1,4,5,3,1,1,3]
输出： 12
解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 =
12。
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
     * 动态规划
     * !其实这里不需要用dp数组来保存dp结果
     * !需要dp保存的只有[前一个预约接了的最大时间]和[前一个预约没接的最大时间]
     */
    int massage(vector<int>& nums)
    {
        if (nums.size() == 0) {
            return 0;
        }

        // 分别表示[前一个预约] 没接/接了 的最大时间
        int dp_0, dp_1;
        dp_0 = 0, dp_1 = nums[0];

        int this_0, this_1;
        for (int i = 1; i < nums.size(); i++) {
            this_0 = max(dp_0, dp_1);
            this_1 = dp_0 + nums[i];

            dp_0 = this_0;
            dp_1 = this_1;
        }

        return max(dp_0, dp_1);
    }
};

TEST_CASE("test")
{
    Solution    s;
    vector<int> nums;

    nums = {1, 2, 3, 1};
    REQUIRE(s.massage(nums) == 4);

    nums = {2, 7, 9, 3, 1};
    REQUIRE(s.massage(nums) == 12);

    nums = {2, 1, 4, 5, 3, 1, 1, 3};
    REQUIRE(s.massage(nums) == 12);

    nums = {};
    REQUIRE(s.massage(nums) == 0);
}
