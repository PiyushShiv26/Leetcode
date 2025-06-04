/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdbool.h>  // For bool type
#include <stddef.h>  // For NULL

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL) {
        slow = slow->next;
    }

    struct ListNode *prev = NULL, *next;
    while (slow) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    struct ListNode* left = head;
    struct ListNode* right = prev;
    while (right) {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }

    return true;
}
