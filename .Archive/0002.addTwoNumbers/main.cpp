#include <iostream>
#include <vector>
#include "addTwoNumbers.cpp"

using namespace std;

ListNode *GenNodeList(vector<int> a)
{
    ListNode *l = NULL;
    ListNode *lastNode = NULL;
    for (int i = 0; i < a.size(); i++)
    {
        ListNode *tl = new ListNode(a[i]);

        // 赋值头节点
        if (i == 0)
        {
            l = tl;
        }
        // 链接链表
        else
        {
            lastNode->next = tl;
        }

        lastNode = tl;
    }

    return l;
}

void testCase(vector<int> a, vector<int> b)
{
    ListNode *l1 = GenNodeList(a);
    ListNode *l2 = GenNodeList(b);
    ListNode *l = (Solution()).addTwoNumbers(l1, l2);
    while (true)
    {
        if (l == NULL)
            break;
        cout << l->val;
        l = l->next;
    }
    
    cout << endl;
}

int main()
{
    testCase(vector<int>{2, 4, 3}, vector<int>{5, 6, 4});
    testCase(vector<int>{5}, vector<int>{5});
    testCase(vector<int>{0, 1}, vector<int>{0, 1, 2});
    testCase(vector<int>{}, vector<int>{0, 1});
    testCase(vector<int>{1}, vector<int>{9, 9});
}
