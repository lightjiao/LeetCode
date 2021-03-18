/**
给定 n 个非负整数表示每个宽度为 1
的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6
个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
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
    /**
     * 暴力枚举, 枚举两个点之间是否可以有点可以填充
     * 时间复杂度O(n^3), 过于暴力，超出时间限制
     */
    int trap(vector<int>& height)
    {
        // 记录每个点的雨水
        vector<int> water(height.size(), 0);

        for (int i = 0; i < height.size(); i++) {
            if (height[i] == 0) {
                continue;
            }

            for (int j = i + 2; j < height.size(); j++) {
                if (height[j] == 0) {
                    continue;
                }

                // 计算 i 和 j 中间的点的积水
                for (int k = i + 1; k < j; k++) {
                    int waterK = min(height[i], height[j]) - height[k];
                    water[k]   = max(water[k], waterK);
                }
            }
        }

        return accumulate(water.begin(), water.end(), 0);
    }
};

TEST_CASE("test")
{
    Solution    s;
    vector<int> height;

    height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    REQUIRE(s.trap(height) == 6);

    height = {3, 0, 1, 0, 2};
    REQUIRE(s.trap(height) == 5);

    height = {2, 0, 1, 0, 2};
    REQUIRE(s.trap(height) == 5);

    height = {2, 0, 1, 0, 3};
    REQUIRE(s.trap(height) == 5);

    height = {2, 0, 3, 0, 3};
    REQUIRE(s.trap(height) == 5);
}
