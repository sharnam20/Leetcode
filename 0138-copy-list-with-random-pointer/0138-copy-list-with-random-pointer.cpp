/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL){
            return NULL;
        }
        //approach -1 --------------------------------
        // Node*temp=head;
        // unordered_map<Node*,Node*>mp;
        // while(temp!=NULL){
        //     Node*newnode=new Node(temp->val);//create copy node value same of original
        //     mp[temp]=newnode;
        //     temp=temp->next;
        // }
        // // after this while loop in map original->nwenode with value ;
        // temp=head;
        // while(temp!=NULL){
        //     mp[temp]->next=mp[temp->next];
        //      mp[temp]->random=mp[temp->random];
        //      temp=temp->next;

        // }
        // return mp[head];
        //approach -2-----------------------------
 
    
        
        Node* temp = head;
        
        // Step 1: Insert copy nodes after original nodes
        while(temp != NULL) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        
        // Step 2: Assign random pointers
        temp = head;
        while(temp != NULL) {
            if(temp->random != NULL)
                temp->next->random = temp->random->next;
            
            temp = temp->next->next;
        }
        
        // Step 3: Separate original and copied list
        Node* original = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;
        
        while(original != NULL) {
            original->next = original->next->next;
            
            if(copy->next != NULL)
                copy->next = copy->next->next;
            
            original = original->next;
            copy = copy->next;
        }
        
        return copyHead;
    }
};
 