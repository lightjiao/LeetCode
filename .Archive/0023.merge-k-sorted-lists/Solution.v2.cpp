/**
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 更好的两两合并
     */
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0)
        {
            return NULL;
        }

        int interval = 1;
        int amount   = lists.size();

        while (interval < amount)
        {
            for (int i = 0; i < amount - interval; i += interval * 2)
            {
                lists[i] = mergeTwoSortedLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }

    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        _merge(dummy, l1, l2);
        return dummy->next;
    }

    void _merge(ListNode* cur, ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL && l2 == NULL)
        {
            return;
        }
        else if (l1 != NULL && l2 == NULL)
        {
            cur->next = l1;
            return;
        }
        else if (l1 == NULL && l2 != NULL)
        {
            cur->next = l2;
            return;
        }
        else
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                return _merge(l1, l1->next, l2);
            }
            else
            {
                cur->next = l2;
                return _merge(l2, l1, l2->next);
            }
        }
    }
};

void test(vector<vector<int>> vectorLists, vector<int> expect)
{
    vector<ListNode*> lists;
    for (auto&& list : vectorLists)
    {
        ListNode* pl1 = ListNode::Create(list);
        lists.push_back(pl1);
    }

    ListNode* head;
    Solution  s;

    head = s.mergeKLists(lists);
    REQUIRE(ListNode::ToVector(head) == expect);
}
TEST_CASE("test")
{
    test({{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6});
}
