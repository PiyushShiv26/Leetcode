/*
876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:

1 -> 2 -> |3| -> 4 -> 5

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

1 -> 2 -> 3 -> |4| -> 5 -> 6

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

#include <stddef.h>  // For NULL

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Solution

struct ListNode* middleNode(struct ListNode* head) {
    int count = 0;
    struct ListNode* temp = head;

    // Count the total number of nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Move to the middle node
    temp = head;
    for (int i = 0; i < count / 2; i++) {
        temp = temp->next;
    }

    return temp;
}
