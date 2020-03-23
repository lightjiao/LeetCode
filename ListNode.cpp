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
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// bool ListEqual(ListNode* l1, ListNode* l2);

ListNode* buildList(vector<int> list)
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

vector<int> parseList(ListNode* head)
{
    vector<int> result;
    while (head != NULL) {
        result.push_back(head->val);
        head = head->next;
    }

    return result;
}

#endif