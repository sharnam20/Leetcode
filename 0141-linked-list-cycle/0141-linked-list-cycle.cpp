#include <unordered_set>

class Solution {
public:
    bool hasCycle(ListNode *head) {
      //  approach 1
        unordered_set<ListNode*> visited;

        while (head != NULL) {
            if (visited.find(head) != visited.end()) {
                return true;   // cycle detected
            }

            visited.insert(head);
            head = head->next;
        }

        return false;  // no cycle
    }
};
