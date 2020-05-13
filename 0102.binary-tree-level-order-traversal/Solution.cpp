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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;

        // node, depth
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        while (q.empty() == false)
        {
            auto [p, depth] = q.front();
            q.pop();
            if (p == nullptr)
            {
                continue;
            }

            if ((int)result.size() - 1 < depth)
            {
                result.push_back(vector<int>{});
            }
            result[depth].push_back(p->val);

            q.push({p->left, depth + 1});
            q.push({p->right, depth + 1});
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution  s;
    TreeNode* root;

    vector<vector<int>> result, expect;

    root   = TreeNode::Build({1, 2, 3});
    result = s.levelOrder(root);
    expect = {{1}, {2, 3}};
    REQUIRE(VV::same(result, expect));

    root = TreeNode::Build({3, 9, 20, TreeNode::_Null, TreeNode::_Null, 15, 7});
    result = s.levelOrder(root);
    expect = {
        {3},
        {9, 20},
        {15, 7},
    };
    REQUIRE(VV::same(result, expect));
}
