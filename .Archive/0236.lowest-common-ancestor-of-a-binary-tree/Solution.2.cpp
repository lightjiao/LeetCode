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
     * 记录每个节点的最近的父节点
     * 从p不断往根点移动，并记录下移动轨迹
     * 从q往根节点移动，如果有节点已经访问过，则就是LCA节点
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        fa[root->val] = nullptr;
        dfs(root);
        unordered_map<int, bool> visit;

        while (p != nullptr)
        {
            visit[p->val] = true;

            p = fa[p->val];
        }

        while (q != nullptr)
        {
            if (visit[q->val] == true)
            {
                return q;
            }
            q = fa[q->val];
        }

        return nullptr;
    }

    unordered_map<int, TreeNode*> fa;

    void dfs(TreeNode* root)
    {
        if (root->left != nullptr)
        {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr)
        {
            fa[root->right->val] = root;
            dfs(root->right);
        }
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
