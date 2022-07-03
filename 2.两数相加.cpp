/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = nullptr;
        ListNode *cur = ans, *cur1 = l1, *cur2 = l2;
        bool carry = false;
        while(cur1 || cur2)
        {
            int tmp = (cur1?cur1->val:0) + (cur2?cur2->val:0) + carry;
            carry = tmp / 10;
            if (cur)
            {
                cur->next = new ListNode(tmp % 10);
                cur = cur->next;
            }
            else
            {
                cur = ans = new ListNode(tmp % 10);
            }
            if (cur1) cur1 = cur1->next;
            if (cur2) cur2 = cur2->next;
        }
        if (carry)
        {
            cur->next = new ListNode(carry);
        }
        return ans;
    }
};
// @lc code=end

