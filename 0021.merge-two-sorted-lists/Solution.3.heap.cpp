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
     * 堆排序，并且降低控件复杂度
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        auto f = [](const ListNode* left, const ListNode* right) {
            return left->val > right->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(f)> q(f);
        // priority_queue<ListNode*> q(f);

        if (nullptr != l1)
        {
            q.emplace(l1);
        }
        if (nullptr != l2)
        {
            q.emplace(l2);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail  = dummy;
        while (q.empty() == false)
        {
            ListNode* p = q.top();
            q.pop();
            tail->next = p;
            tail       = p;
            if (p->next != nullptr)
            {
                q.emplace(p->next);
            }
        }

        return dummy->next;
    }
};

void test(vector<int> l1, vector<int> l2, vector<int> expect)
{
    Solution  s;
    ListNode* head;

    head = s.mergeTwoLists(ListNode::Create(l1), ListNode::Create(l2));
    REQUIRE(ListNode::ToVector(head) == expect);
}

TEST_CASE("test")
{
    test({1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4});
}