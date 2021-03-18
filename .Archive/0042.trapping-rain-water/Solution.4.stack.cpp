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
     * 根本的思路是利用栈的先进先出，横向的计算积水，比较讨巧
     * 
     * 我们在遍历数组时维护一个栈。
     * 如果当前的条形块小于或等于栈顶的条形块，我们将条形块的索引入栈，意思是当前的条形块被栈中的前一个条形块界定。
     * 如果我们发现一个条形块长于栈顶，我们可以确定栈顶的条形块被当前条形块和栈的前一个条形块界定，
     * 因此我们可以弹出栈顶元素并且累加答案到ans
     */
    int trap(vector<int>& height)
    {
        // 保存高度下标的栈
        stack<int> stk;

        int result = 0, current = 0;
        while (current < height.size()) {
            // 计算积水( 宽度乘以高度 )
            while (stk.empty() == false &&
                   height[current] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }

                int d = current - stk.top() - 1;
                int h = min(height[current], height[stk.top()]) - height[top];
                result += d * h;
            }
            stk.push(current);
            current++;
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
