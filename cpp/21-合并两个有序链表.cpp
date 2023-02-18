/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode* head = nullptr;
       ListNode* cur = nullptr;
       while(list1 && list2){
            ListNode* tmp = nullptr;
            if (list1->val <= list2->val) {
                tmp = list1;
                list1 = list1->next;
            } else {
                tmp = list2;
                list2 = list2->next;
            }
            if (head == nullptr) {
                head = tmp;
                cur = tmp;
            } else {
                cur->next = tmp;
                cur = cur->next;
            }
       }
       if (list1) {
            if (head == nullptr) {
                head = list1;
            } else {
                cur->next = list1;
            }
       }
       if (list2) {
            if (head == nullptr) {
                head = list2;
            } else {
                cur->next = list2;
            }
       }
       return head;
    }
};
// @lc code=end

