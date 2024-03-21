/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto node : lists){
            if(node){
                pq.push(node);
            }
        }

        while (!pq.empty())
        {
//先把头节点加进特制的最小堆，然后逐个取出节点，用指针顺着链表再把每个元素放进最小堆。每次push在堆内都会swim和sink调平。
//堆底加，堆顶出，直到都加进去后就不停地从堆顶取值放入p的list
            auto minNode = pq.top();
            pq.pop();
            p->next = minNode;
            if(minNode->next){
                pq.push(minNode->next);
            }
            p = p->next;
        }
        
        return dummy->next;
    }

private:
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
};
// @lc code=end

