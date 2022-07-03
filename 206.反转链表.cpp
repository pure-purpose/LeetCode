/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head, *prev=nullptr;
        while(curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }
        return prev;
        // std::stack<int> data;
        // while(head != NULL)
        // {
        //     data.push(head->val);
        //     head = head->next;
        // }
        // ListNode *reversedList = new ListNode(data.top());
        // ListNode *tmp = reversedList;
        // while(!data.empty())
        // {
        //     data.pop();
        //     ListNode *newNode = new ListNode(data.top());
        //     tmp->next = newNode;
        //     tmp = newNode;
        // }
        // return reversedList;
    }
};
// @lc code=end

