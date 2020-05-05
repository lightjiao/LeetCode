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
     * 快速的求左子树最大的数字，和求右子树最小的数字
     */
    bool isValidBST(TreeNode* root)
    {
        bool isValid = true;

        if (root == nullptr)
        {
            return isValid;
        }

        if (treeMax(root->left) != nullptr &&
            treeMax(root->left)->val >= root->val)
        {
            isValid = false;
        }

        if (treeMin(root->right) != nullptr &&
            treeMin(root->right)->val <= root->val)
        {
            isValid = false;
        }

        return isValid && isValidBST(root->left) && isValidBST(root->right);
    }

    unordered_map<TreeNode*, TreeNode*> nodesMin;
    unordered_map<TreeNode*, TreeNode*> nodesMax;

    TreeNode* treeMin(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (nodesMin.find(root) != nodesMin.end())
        {
            return nodesMin[root];
        }

        TreeNode* minNode = root;

        if (root->left != nullptr && treeMin(root->left)->val < minNode->val)
        {
            minNode = treeMin(root->left);
        }

        if (root->right != nullptr && treeMin(root->right)->val < minNode->val)
        {
            minNode = treeMin(root->right);
        }

        nodesMin.emplace(root, minNode);

        return minNode;
    }

    TreeNode* treeMax(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (nodesMax.find(root) != nodesMax.end())
        {
            return nodesMax[root];
        }

        TreeNode* maxNode = root;

        if (root->left != nullptr && treeMax(root->left)->val > maxNode->val)
        {
            maxNode = treeMax(root->left);
        }

        if (root->right != nullptr && treeMax(root->right)->val > maxNode->val)
        {
            maxNode = treeMax(root->right);
        }

        nodesMax.emplace(root, maxNode);

        return maxNode;
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
