/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
     Node* dummy = new Node(0);
        Node*curr;
     Node*prev=dummy;
     stack<Node*>st;
     st.push(head);
     if(head == NULL)
            return NULL;
    while(!st.empty()) {
        curr=st.top();
        st.pop();
        prev->next=curr;
        curr->prev=prev;
        if(curr->next!=NULL){
        st.push(curr->next);
        }
        if(curr->child!=NULL){
        st.push(curr->child);
        curr->child=NULL;
        }
        prev=curr;
    }
     dummy->next->prev = NULL;
        return dummy->next;
    }
    
};