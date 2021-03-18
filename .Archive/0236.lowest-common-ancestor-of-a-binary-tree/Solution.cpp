/**
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点
p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
的深度尽可能大（一个节点也可以是它自己的祖先）。”

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
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
    /**
     * 遍历出每一个节点拥有的节点列表，用map<ptr, vector<ptr>>保存映射
     * 最后找出最小的map
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // 构建 节点-子节点列表的 map
        auto resultMap = buildMap(root);

        // 找最小父节点 BFS
        auto f = [](unordered_map<int, unordered_set<int>>& lambdaMap,
                    int lambdaResult, int lambdaP, int lambdaQ) {
            return lambdaMap[lambdaResult].count(lambdaP) &&
                   lambdaMap[lambdaResult].count(lambdaQ);
        };

        TreeNode* result = root;
        while (true)
        {
            if (result->left && f(resultMap, result->left->val, p->val, q->val))
            {
                result = result->left;
            }
            else if (result->right &&
                     f(resultMap, result->right->val, p->val, q->val))
            {
                result = result->right;
            }
            else
            {
                break;
            }
        }

        return result;
    }

    unordered_map<int, unordered_set<int>> buildMap(TreeNode* root)
    {
        unordered_map<int, unordered_set<int>> result;

        // <node, parentNodes>
        using QuqueNode = pair<TreeNode*, unordered_set<TreeNode*>>;
        queue<QuqueNode> q;
        q.push({root, {root}});
        // q.emplace(root, {root});

        while (q.empty() == false)
        {
            auto n = q.front();
            q.pop();
            if (n.first == nullptr)
            {
                continue;
            }

            // 记录所有父节点
            result[n.first->val] = {};
            // 反向的记录所有父节点拥有的子节点值
            for (auto&& parentN : n.second)
            {
                result[parentN->val].emplace(n.first->val);
            }

            // 添加子节点
            auto pl = n.second;
            pl.emplace(n.first->left);
            q.push({n.first->left, pl});
            auto pr = n.second;
            pr.emplace(n.first->right);
            q.push({n.first->right, pr});
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution  s;
    TreeNode* root = TreeNode::Build(
        {3, 5, 1, 6, 2, 0, 8, TreeNode::_Null, TreeNode::_Null, 7, 4});
    TreeNode* p = new TreeNode(0);
    TreeNode* q = new TreeNode(0);

    p->val = 5;
    q->val = 1;
    REQUIRE(s.lowestCommonAncestor(root, p, q)->val == 3);

    p->val = 0;
    q->val = 8;
    REQUIRE(s.lowestCommonAncestor(root, p, q)->val == 1);

    p->val = 5;
    q->val = 4;
    REQUIRE(s.lowestCommonAncestor(root, p, q)->val == 5);
}
