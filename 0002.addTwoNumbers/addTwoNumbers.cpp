#include <iostream>
#include <vector>
#include "../listnode.cpp"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l = NULL;
        ListNode *tl = NULL;
        bool firstNodeFlag = true;
        int overFlowValue = 0;
        while (true)
        {
            if (l1 == NULL && l2 == NULL && overFlowValue == 0)
                break;

            int val1 = 0, val2 = 0;
            if (l1 != NULL)
                val1 = l1->val;
            if (l2 != NULL)
                val2 = l2->val;

            tl = appendValueNode(tl, val1 + val2 + overFlowValue, overFlowValue);
            if (firstNodeFlag)
            {
                l = tl;
                firstNodeFlag = false;
            }

            if (l1 != NULL)
            {
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                l2 = l2->next;
            }
        }

        return l;
    }

private:
    ListNode *appendValueNode(ListNode *l, int val, int &overflowValue)
    {
        overflowValue = 0;
        if (val < 10)
        {
            return appendNode(l, val);
        }

        overflowValue = val / 10;
        return appendNode(l, val - 10);
    }

    ListNode *appendNode(ListNode *l, int singleVal)
    {
        ListNode *tl = new ListNode(singleVal);
        if (l != NULL)
        {
            l->next = tl;
        }

        return tl;
    }
};
