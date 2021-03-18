/**
 * 给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1
的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。 说明:

假设你总是可以到达数组的最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    int jump(vector<int>& nums)
    {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (maxPos >= i)
            {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end)
                {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<int> param;

    param = {2, 3, 1, 1, 4};
    REQUIRE(s.jump(param) == 2);

    param = {3, 2, 1};
    REQUIRE(s.jump(param) == 1);

    param = {2, 3, 1};
    REQUIRE(s.jump(param) == 1);

    param = {1, 2, 1, 1, 1};
    REQUIRE(s.jump(param) == 3);
}
