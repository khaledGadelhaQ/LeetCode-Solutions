class node {
public:
    int key;
    int val;
    node* next;
    node* prev;
    node(int key_, int val_) : key(key_), val(val_), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, node*> umap;
    node* head;
    node* tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (umap.find(key) != umap.end()) {
            node* move = umap[key];
            moveNode(move);
            return move->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (umap.find(key) != umap.end()) {
            // Key exists, update the value and move it to the front
            node* move = umap[key];
            move->val = value;
            moveNode(move);
        } else {
            // Key doesn't exist
            if (umap.size() >= capacity) {
                // Remove the least recently used element
                umap.erase(tail->key);
                removeNode(tail);
            }

            // Insert the new node at the front
            node* newNode = new node(key, value);
            umap[key] = newNode;
            insertNode(newNode);
        }
    }

private:
    void moveNode(node* move) {
        if (move == head) {
            return; // Already at the front
        }

        if (move == tail) {
            tail = move->prev;
        }

        move->prev->next = move->next;
        if (move->next) {
            move->next->prev = move->prev;
        }

        insertNode(move);
    }

    void insertNode(node* newNode) {
        newNode->next = head;
        newNode->prev = nullptr;

        if (head) {
            head->prev = newNode;
        }

        head = newNode;

        if (!tail) {
            tail = newNode;
        }
    }

    void removeNode(node* delNode) {
        if (delNode == head) {
            head = delNode->next;
        } else {
            delNode->prev->next = delNode->next;
        }

        if (delNode == tail) {
            tail = delNode->prev;
        } else {
            delNode->next->prev = delNode->prev;
        }

        delete delNode;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */