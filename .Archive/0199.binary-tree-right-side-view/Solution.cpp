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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> result;

        stack<pair<TreeNode*, int>> s;
        s.emplace(root, 1);
        int resultDepth = 0;
        while (s.empty() == false)
        {
            auto t = s.top().first;
            auto d = s.top().second;
            s.pop();
            if (nullptr == t)
            {
                continue;
            }

            if (d > resultDepth)
            {
                result.push_back(t->val);
                resultDepth++;
            }

            if (nullptr != t->left)
            {
                // s.push(pair<TreeNode*, int>{t->left, d + 1});
                s.push({t->left, d + 1});
            }
            if (nullptr != t->right)
            {
                s.push({t->right, d + 1});
            }
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution  s;
    TreeNode* root;

    root = TreeNode::Build({1, 2, 3, TreeNode::_Null, 5, TreeNode::_Null, 4});
    TreeNode::Print(root);
    REQUIRE(s.rightSideView(root) == vector<int>{1, 3, 4});
};
