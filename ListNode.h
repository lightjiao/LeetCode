#ifndef __LIST_NODE__
#define __LIST_NODE__

#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildList(std::vector<int> list)
{
    ListNode* head = NULL;

    ListNode* preNode = NULL;
    for (int i = 0; i < list.size(); i++) {
        ListNode* node = new ListNode(list[i]);
        node->next     = NULL;
        if (i == 0) {
            head = node;
        }
        if (i > 0) {
            preNode->next = node;
        }

        preNode = node;
    }

    return head;
}

std::vector<int> parseList(ListNode* head)
{
    std::vector<int> result;
    while (head != NULL) {
        result.push_back(head->val);
        head = head->next;
    }

    return result;
}

#endif