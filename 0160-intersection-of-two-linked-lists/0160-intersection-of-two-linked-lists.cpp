/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       // bruteforce 1
        
        // ListNode* a = headA;
        
        // while(a != NULL) {
            
            // ListNode* b = headB;
            
        //     while(b != NULL) {
                
        //         if(a == b) {     
        //             return a;    
        //         }
                
        //         b = b->next;
        //     }
            
        //     a = a->next;
        // }
        
        // return NULL;  

//    ---------------- bruteforce 2
      // we use set
      unordered_set<ListNode*>s;
      ListNode* a = headA;
      while(a!= NULL){
        s.insert(a);
         a = a->next;
      }
      ListNode* b = headB;
      while(b!=NULL){
        if(s.find(b)!=s.end()){
            return b;
        }
         b = b->next;
       
      }
      return NULL;
    }
};
  