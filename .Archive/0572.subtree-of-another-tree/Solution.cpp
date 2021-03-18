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
     * 梭哈的一个一个节点的对比
     */
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        stack<TreeNode*> st;
        st.push(s);

        while (st.empty() == false)
        {
            TreeNode* n = st.top();
            st.pop();
            if (n == nullptr)
            {
                continue;
            }

            st.push(n->right);
            st.push(n->left);

            if (n->val == t->val && true == _treeEqual(n, t))
            {
                return true;
            }
        }

        return false;
    }

    bool _treeEqual(TreeNode* s, TreeNode* t)
    {
        if (s == nullptr && t == nullptr)
        {
            return true;
        }

        if (s == nullptr && t != nullptr)
        {
            return false;
        }

        if (s != nullptr && t == nullptr)
        {
            return false;
        }

        if (s->val != t->val)
        {
            return false;
        }

        return _treeEqual(s->left, t->left) && _treeEqual(s->right, t->right);
    }
};

TEST_CASE("test")
{
    Solution _s;

    TreeNode* s;
    TreeNode* t;

    s = TreeNode::Build({3, 4, 5, 1, 2});
    t = TreeNode::Build({4, 1, 2});
    REQUIRE(_s.isSubtree(s, t) == true);

    s = TreeNode::Build({3, 4, 5, 1, 2, TreeNode::_Null, TreeNode::_Null,
                         TreeNode::_Null, TreeNode::_Null, 0});
    t = TreeNode::Build({4, 1, 2});
    REQUIRE(_s.isSubtree(s, t) == false);
}
