/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* small = dummy1;
        ListNode* big = dummy2;
        ListNode* p = head;

        while (p!=nullptr)
        {
            if(p->val<x){
                small->next = p;
                small = small->next;
            }else{
                big->next = p;
                big = big->next;
            }

            ListNode* tmp = p->next;
            p->next = nullptr;
            p = tmp;
        }

        small->next = dummy2->next;

        return dummy1->next;
    }
};
// @lc code=end

