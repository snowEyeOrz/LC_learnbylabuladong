/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;

        int n = getlength(head);
        if(n == 1) return head;
        if(k % n == 0) return head;
        k = k % n;
        ListNode* step1 = nullptr;
        ListNode* step2 = nullptr;
        ListNode* step3 = nullptr;

        step1 = reverseN(head, n);
        step2 = reverseN(step1, k);
        step3 = reverseBetween(step2, k + 1, n);

        return step3;
    }

    int getlength(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* successor = nullptr;
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }

        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }

};
// @lc code=end

