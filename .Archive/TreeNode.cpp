#ifndef __TREE_NODE__
#define __TREE_NODE__

#include "limits.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct TreeNode
{
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    static const int _Null = INT_MIN;

    /**
     * 二叉树的顺序存储结构:
     * 对于i个元素，它的左右子节点在数组的位置分别为：2*i+1、2*i+2
     * example:
     * @input : [ 1, 2, 3, null, 5, null, 4 ]
     * @struct :
     *     1
     *   /   \
     *  2     3
     *   \     \
     *    5     4
     */
    static TreeNode* Build(vector<int> nums)
    {
        vector<TreeNode*> tempList(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            if (n == _Null)
            {
                continue;
            }

            TreeNode* t = new TreeNode(n);
            tempList[i] = t;
            if (i == 0)
            {
                continue;
            }

            int parentIndex = (i - 1) / 2;
            if (i % 2 == 0)
            {
                tempList[parentIndex]->right = t;
            }
            else
            {
                tempList[parentIndex]->left = t;
            }
        }

        return tempList[0];
    }

    static void Print(TreeNode* root)
    {
        if (nullptr == root)
        {
            return;
        }

        cout << root->val;
        Print(root->left);
        Print(root->right);
    }
};

#endif