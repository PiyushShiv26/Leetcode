/*
83. Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:

Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/

#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL){
        return head;
    }
    struct ListNode *curr = head;
    
    while(curr!=NULL&&curr->next!=NULL){
        if(curr->val==curr->next->val){
            struct ListNode *duplicateNode = curr->next;
            curr->next = duplicateNode->next;
            free(duplicateNode);
        } else {
            curr = curr->next;
        }
    }
    return head;
}