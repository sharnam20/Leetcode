class MyLinkedList {
public:
    
    class Node {
    public:
        int val;
        Node* next;
        Node* prev;
        
        Node(int x) {
            val = x;
            next = NULL;
            prev = NULL;
        }
    };
    
    Node* head;
    Node* tail;
    int size;
    
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size)
            return -1;
        
        Node* temp = head;
        for(int i = 0; i < index; i++)
            temp = temp->next;
        
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        
        if(size == 0) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        
        if(size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
            return;
        
        if(index == 0) {
            addAtHead(val);
            return;
        }
        
        if(index == size) {
            addAtTail(val);
            return;
        }
        
        Node* temp = head;
        for(int i = 0; i < index - 1; i++)
            temp = temp->next;
        
        Node* newNode = new Node(val);
        
        newNode->next = temp->next;
        newNode->prev = temp;
        
        temp->next->prev = newNode;
        temp->next = newNode;
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        
        if(index == 0) {
            Node* temp = head;
            head = head->next;
            
            if(head != NULL)
                head->prev = NULL;
            else
                tail = NULL;
            
            delete temp;
            size--;
            return;
        }
        
        if(index == size - 1) {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            
            delete temp;
            size--;
            return;
        }
        
        Node* temp = head;
        for(int i = 0; i < index; i++)
            temp = temp->next;
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        
        delete temp;
        size--;
    }
};