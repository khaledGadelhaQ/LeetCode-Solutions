class MyLinkedList {
private:
  struct node{
    int val;
    node* next;
    node(int val_): val(val_), next(nullptr){}
  };
public:
    node* head;
    int sz ;

    MyLinkedList() {
        head = nullptr;
        sz =0 ;
    }
    
    int get(int index) {
        if (index < 0 || index >= sz) return -1;
        node* cur = head;
        while(index--){
          cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        node* new_node = new node(val);
        new_node->next = head;
        head = new_node;         
        sz++;
    }
    
    void addAtTail(int val) {
        if(sz == 0){ addAtHead(val); return;}
        node* new_node = new node(val);
        node* cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = new_node;
        sz++;

    }
    
    void addAtIndex(int index, int val) {
        if(index > sz){return ;}
        if (index <= 0 ){
            addAtHead(val); 
        }else if (index == sz){
            addAtTail(val);
        }else{
            node* cur = head;
            while(--index){
                cur = cur->next;
            }
            node* new_node = new node(val);
            new_node->next = cur->next;
            cur->next = new_node;
            sz++;
        }

    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= sz) return;
        if(index == 0){
            node* tmp = head;
            head = head->next;
            sz--;
            delete tmp;
        }else{
            node* cur = head;
            while(--index){
             cur = cur->next;
            }

            node* tmp = cur->next;
            if(cur->next)
              cur->next = tmp->next;
            delete tmp;
            sz--;
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */