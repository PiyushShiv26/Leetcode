/*
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL && list2 == NULL){
        return list1;
    }
    struct ListNode *dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *curr = dummyHead;

    struct ListNode *p1 = list1;
    struct ListNode *p2 = list2;

    while(p1!=NULL && p2!=NULL){
        if(p1->val <= p2->val){
            curr->next = p1;
            p1 = p1->next;
        } else {
            curr->next = p2;
            p2 = p2->next;
        }
        curr = curr->next;
    }

    if(p1 != NULL) {
    curr->next = p1;
    } else {
        curr->next = p2;
    }

    return dummyHead->next;
}