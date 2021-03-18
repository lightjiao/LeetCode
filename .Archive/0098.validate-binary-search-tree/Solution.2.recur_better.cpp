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
     * 更简洁, 效率也更高的的递归实现
     */
    bool isValidBST(TreeNode* root)
    {
        return Helper(root, nullptr, nullptr);
    }

    /**
     * @root:  要检查的节点
     * @lower: 当前节点的值的上限, 为null,
     *         或者递归调用时, 将根节点传入到右子树的递归
     * @upper: 当前节点的值的下线, 为null
     *         或者递归调用时, 将根节点传入到左子树的递归
     */
    bool Helper(TreeNode* root, TreeNode* lower, TreeNode* upper)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (lower != nullptr && root->val <= lower->val)
        {
            return false;
        }

        if (upper != nullptr && root->val >= upper->val)
        {
            return false;
        }

        return Helper(root->left, lower, root) &&
               Helper(root->right, root, upper);
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
