/**
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    int singleNumber(vector<int>& nums)
    {
        int result = 0;
        for (auto&& n : nums)
        {
            result = (result ^ n);
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution    s;
    vector<int> nums;

    nums = {2, 2, 1};
    REQUIRE(s.singleNumber(nums) == 1);

    nums = {4, 1, 2, 1, 2};
    REQUIRE(s.singleNumber(nums) == 4);
}
