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
        
        // Edge cases
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        // Step 1: Find length and last node
        ListNode* tail = head;
        int length = 1;
        
        while(tail->next != NULL) {
            tail = tail->next;
            length++;
        }
        
        // Step 2: Reduce k
        k = k % length;
        if(k == 0)
            return head;
        
        // // Step 3: Make list circular
        tail->next = head;
        
        // Step 4: Find new tail
        int steps = length - k;
        ListNode* newTail = head;
        
        for(int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }
        
        // Step 5: Break circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        
        return newHead;
    }
};