class LRUCache {
public:
    class Node {
    public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key_val, int val_o){
        key = key_val;
        val = val_o;
    }
};
Node *head = new Node(-1, -1);
Node *tail = new Node(-1,-1);
int cap;
unordered_map<int, Node*>cmap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(Node *newnode){
        Node *temp = head->next;
        newnode->next=temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;

    }
    void deletenode(Node *delnode){
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key) {
         if (cmap.find(key) != cmap.end()) {
            Node* resnode = cmap[key];
            int res = resnode->val;
            cmap.erase(key);
            deletenode(resnode);
            addnode(resnode);
            cmap[key] = head->next;
            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(cmap.find(key)!= cmap.end()){
            Node *existingNode = cmap[key];
            cmap.erase(key);
            deletenode(existingNode);
        }
        if(cmap.size() == cap){
            cmap.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key, value));
        cmap[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */