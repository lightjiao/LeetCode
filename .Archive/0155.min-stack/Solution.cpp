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

template <typename _Ty, typename _Container = vector<_Ty>,
          typename _Pr = less<typename _Container::value_type>>
class MyPriorityQueue : public priority_queue<_Ty, _Container, _Pr>
{
public:
    bool remove(const _Ty& value)
    {
        auto it = find(this->c.begin(), this->c.end(), value);

        if (it != this->c.end())
        {
            this->c.erase(it);
            make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }

        return false;
    }
};

class MinStack
{
public:
    /**
     * 给stack加一个堆排序
     */
    MinStack() {}

    MyPriorityQueue<int, vector<int>, greater<int>> pq;

    stack<int> stk;

    void push(int x)
    {
        stk.push(x);
        pq.push(x);
    }

    void pop()
    {
        pq.remove(stk.top());
        stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return pq.top();
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
