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
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
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
    //   unordered_set<ListNode*>s;
    //   ListNode* a = headA;
    //   while(a!= NULL){
    //     s.insert(a);
    //      a = a->next;
    //   }
    //   ListNode* b = headB;
    //   while(b!=NULL){
    //     if(s.find(b)!=s.end()){
    //         return b;
    //     }
    //      b = b->next;
       
    //   }
    //   return NULL;
    // optimal 1 using 2 pointer 
    //   ListNode* a = headA;
    //   ListNode* b = headB;
    //  if(headA == NULL || headB == NULL)
    //         return NULL;
    //   while(a!=b){
    //     if(a==NULL){
    //         a=headB;
    //     }
    //     else{
    //         a=a->next;
    //     }
    //     if(b==NULL){
    //         b=headA;
    //     }
    //     else{
    //         b=b->next;
    //     }
    //   }
    //   return a;

    // optimal 2


    int getLength(ListNode* head) {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        int diff = abs(lenA - lenB);
        
        // Move longer list forward
        if(lenA > lenB) {
            while(diff--) {
                a = a->next;
            }
        } else {
            while(diff--) {
                b = b->next;
            }
        }
        
        // Move both together
        while(a != NULL && b != NULL) {
            if(a == b) {
                return a;
            }
            a = a->next;
            b = b->next;
        }
        
        return NULL;
    }
};
 
  