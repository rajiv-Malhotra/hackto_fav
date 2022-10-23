#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    ListNode *removeNode(ListNode *head, int key)
    {
        ListNode *start = new ListNode();
        ListNode *temp = start;
        ListNode *ptr = head;
        int count = 1;
        while (ptr)
        {
            if (count != key)
            {
                ListNode *n = new ListNode(ptr->val);
                temp->next = n;
                temp = n;
            }
            ptr = ptr->next;
            count++;
        }
        return start->next;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *ptr = head;
        int count = 0;
        while (ptr)
        {
            count++;
            ptr = ptr->next;
        }
        int len = count;
        if (len == 1)
            return NULL;

        int key = len + 1 - n;
        ListNode *resHead = removeNode(head, key);
        return resHead;
    }
};