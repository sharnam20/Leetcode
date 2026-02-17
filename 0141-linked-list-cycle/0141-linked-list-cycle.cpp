#include <unordered_set>

class Solution {
public:
    bool hasCycle(ListNode *head) {
    //   //  approach 1
    //     unordered_set<ListNode*> visited;

    //     while (head != NULL) {
    //         if (visited.find(head) != visited.end()) {
    //             return true;   // cycle detected
    //         }

    //         visited.insert(head);
    //         head = head->next;
    //     }

    //     return false;  // no cycle

    // slow and fast pointer
     if (head == NULL || head->next == NULL)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          
            fast = fast->next->next;    

            if (slow == fast) {
                return true;   
            }
        }

        return false;  
    }
};
