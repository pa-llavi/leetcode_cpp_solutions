/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []
 
Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
*/

/*********************************************** Solution-1 Iterative *****************************************/
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) {
            return head;
        }
        ListNode *prev = NULL, *tmp = head;
        
        while(head) {
            if(head->val != val) {
                prev = head;

            } else {
                if(prev != NULL) {
                    prev->next = head->next;
                } else {
                    tmp = head->next;
                }
            }
            head = head->next;
        }
        return tmp;
    }
};

/******************************************************* Solution-2 Recursive ******************************************/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // base case
        if(head == NULL) {
            return head;
        }
        
        // recursive call
        head->next = removeElements(head->next, val);
        
        // calculation
        if(head->val == val) {
            return head->next;
        }
        return head;
    }
};
