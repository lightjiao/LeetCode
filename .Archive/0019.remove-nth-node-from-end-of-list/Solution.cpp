/**
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
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
     * 双指针？快慢指针？
     * 指针A与指针B相差n个节点，同步遍历，当A遍历结束时，B即在需要删除的节点(或者前一个节点)
     */
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }

        ListNode *quickPoint = head, *slowPoint = head;

        while (true)
        {
            if (quickPoint->next == NULL)
            {
                break;
            }

            quickPoint = quickPoint->next;
            if (n == 0)
            {
                slowPoint = slowPoint->next;
            }
            else
            {
                n--;
            }
        }
        // 删除的节点是头节点的时候
        if (n > 0)
        {
            ListNode* deleteNode = head;

            head = head->next;
            delete deleteNode;
        }
        else
        {
            ListNode* deleteNode = slowPoint->next;

            slowPoint->next = slowPoint->next->next;
            delete deleteNode;
        }

        return head;
    }
};

TEST_CASE("test")
{
    Solution  s;
    ListNode* head;

    head = s.removeNthFromEnd(ListNode::Create({1, 2, 3, 4, 5}), 2);
    REQUIRE(ListNode::ToVector(head) == vector<int>{1, 2, 3, 5});
}
