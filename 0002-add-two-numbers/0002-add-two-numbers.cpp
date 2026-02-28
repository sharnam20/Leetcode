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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*t1=l1;
        ListNode*t2=l2;
        int carry=0;
       
        ListNode*dummy=new ListNode(0);
        ListNode *temp=dummy;
        while(t1!=NULL || t2!=NULL|| carry!=0){
            int sum=carry;
            if(t1!=NULL){
                sum+=t1->val;
                t1=t1->next;
            }
             if(t2!=NULL){
                sum+=t2->val;
                t2=t2->next;
            }
            temp->next=new ListNode(sum%10);
             carry = sum / 10;
           temp = temp->next;  
        }
        return dummy->next;
    }
};