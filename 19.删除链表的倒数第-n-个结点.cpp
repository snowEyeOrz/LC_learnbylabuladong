/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = findFromEnd(dummy, n + 1);
        //      ListNode* p = findFromEnd(head, n+1);
        p->next = p->next->next;

        return dummy->next;
    }

    ListNode *findFromEnd(ListNode *head, int k)
    {
        ListNode *p1 = head;
        ListNode *p2 = head;

        for (int i = 0; i < k; i++)
        {
            p1 = p1->next;
        }

        while (p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
// @lc code=end
