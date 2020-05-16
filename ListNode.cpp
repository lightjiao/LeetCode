#ifndef __LIST_NODE__
#define __LIST_NODE__

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;

    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

    static bool Equal(ListNode* l1, ListNode* l2)
    {
        return ToVector(l1) == ToVector(l2);
    }

    static bool Equal(ListNode* l1, vector<int>& v2)
    {
        return ToVector(l1) == v2;
    }

    static ListNode* Create(vector<int> list)
    {
        ListNode* head = NULL;

        ListNode* preNode = NULL;
        for (int i = 0; i < list.size(); i++)
        {
            ListNode* node = new ListNode(list[i]);
            node->next     = NULL;
            if (i == 0)
            {
                head = node;
            }
            if (i > 0)
            {
                preNode->next = node;
            }

            preNode = node;
        }

        return head;
    }

    static vector<int> ToVector(ListNode* head)
    {
        vector<int> result;
        while (head != NULL)
        {
            result.push_back(head->val);
            head = head->next;
        }

        return result;
    }
};

#endif