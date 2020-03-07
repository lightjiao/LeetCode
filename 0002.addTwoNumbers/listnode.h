#ifndef __LIST_NODE__
#define __LIST_NODE__


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif