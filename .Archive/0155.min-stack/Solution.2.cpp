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

class MinStack
{
    stack<int> x_stack;
    stack<int> min_stack;

public:
    /**
     * 添加一个辅助栈，辅助栈与栈同步的操作入栈、出栈
     * 每个元素入栈时，同步将当前栈中最小元素入栈到辅助栈
     * 当一个元素要入栈时，我们取当前辅助栈的栈顶存储的最小值，与当前元素比较得出最小值，将这个最小值插入辅助栈中
     */
    MinStack()
    {
        min_stack.push(INT_MAX);
    }

    void push(int x)
    {
        x_stack.push(x);
        min_stack.push(min(x, min_stack.top()));
    }

    void pop()
    {
        min_stack.pop();
        x_stack.pop();
    }

    int top()
    {
        return x_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

TEST_CASE("test")
{
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    REQUIRE(minStack.getMin() == -3);  // --> 返回 -3.
    minStack.pop();
    REQUIRE(minStack.top() == 0);      // --> 返回 0.
    REQUIRE(minStack.getMin() == -2);  // --> 返回 -2.
}
