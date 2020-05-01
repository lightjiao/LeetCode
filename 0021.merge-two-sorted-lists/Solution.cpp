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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy   = new ListNode(0);
        ListNode* curNode = dummy;
        while (true)
        {
            if (l1 != NULL && l2 != NULL)
            {
                if (l1->val > l2->val)
                {
                    curNode->next = l2;
                    curNode       = l2;
                    l2            = l2->next;
                }
                else
                {
                    curNode->next = l1;
                    curNode       = l1;
                    l1            = l1->next;
                }
            }
            else if (l1 == NULL && l2 != NULL)
            {
                curNode->next = l2;
                curNode       = l2;
                l2            = l2->next;
            }
            else if (l2 == NULL && l1 != NULL)
            {
                curNode->next = l1;
                curNode       = l1;
                l1            = l1->next;
            }

            if (l1 == NULL && l2 == NULL)
            {
                break;
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