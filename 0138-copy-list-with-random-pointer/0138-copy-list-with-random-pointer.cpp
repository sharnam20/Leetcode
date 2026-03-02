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
        Node*temp=head;
        unordered_map<Node*,Node*>mp;
        while(temp!=NULL){
            Node*newnode=new Node(temp->val);//create copy node value same of original
            mp[temp]=newnode;
            temp=temp->next;
        }
        // after this while loop in map original->nwenode with value ;
        temp=head;
        while(temp!=NULL){
            mp[temp]->next=mp[temp->next];
             mp[temp]->random=mp[temp->random];
             temp=temp->next;

        }
        return mp[head];
    }
};