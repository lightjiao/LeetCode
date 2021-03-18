/**
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * LDR: 中序遍历, 左 -> 根 -> 右
     * 完全二叉搜索树在中序遍历时, 值是严格递增的, 所以……
     */
    bool isValidBST(TreeNode* root)
    {
        TreeNode* p = root;

        stack<TreeNode*> s;
        // 设置最小值
        long preVal = (long)INT_MIN - 1;

        while (s.empty() == false || p != nullptr)
        {
            while (p != nullptr)
            {
                s.push(p);
                p = p->left;
            }

            p = s.top();
            s.pop();

            // 二叉搜索树在中序遍历时是严格递增的
            if (p->val <= preVal)
            {
                return false;
            }

            preVal = p->val;
            p      = p->right;
        }

        return true;
    }
};

TEST_CASE("test")
{
    Solution s;

    REQUIRE(s.isValidBST(TreeNode::Build({1, 1})) == false);
    REQUIRE(s.isValidBST(TreeNode::Build({2, 1, 3})) == true);
    REQUIRE(s.isValidBST(TreeNode::Build(
                {5, 1, 4, TreeNode::_Null, TreeNode::_Null, 3, 6})) == false);

    REQUIRE(s.isValidBST(TreeNode::Build({10, 5, 15, TreeNode::_Null,
                                          TreeNode::_Null, 6, 20})) == false);
}
