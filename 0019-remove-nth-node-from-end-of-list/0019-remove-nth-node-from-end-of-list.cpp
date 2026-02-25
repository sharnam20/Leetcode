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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int count = 0;
        ListNode* temp = head;
        
        // Step 1: Count length
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        // Step 2: If first node needs to be removed
        if(n == count) {
            return head->next;
        }
        
        // Step 3: Go to node before the one to delete
        temp = head;
        int diff = count - n;
        
        for(int i = 1; i < diff; i++) {
            temp = temp->next;
        }
        
        // Step 4: Delete node
        temp->next = temp->next->next;
        
        return head;
    }
};