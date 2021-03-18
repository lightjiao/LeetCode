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
     * DP + Solution2 结合
     * 时间复杂度O(n), 空间复杂度 O(n)
     * 对于每个点的左右max提前用DP计算好
     */
    int trap(vector<int>& height)
    {
        if (height.size() == 0) {
            return 0;
        }

        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());

        leftMax[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        rightMax[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        int result = 0;
        for (int i = 0; i < height.size(); i++) {
            result += min(leftMax[i], rightMax[i]) - height[i];
        }

        return result;
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
