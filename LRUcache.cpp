class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;
            Node(int key, int val)
            {
                this->key=key;
                this->val=val;
            }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>m;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;

        
    }
    void erase(Node* node)
    {
        Node* temp=node->prev;
        Node* next=node->next;
        temp->next=next;
        next->prev=temp;
        m.erase(node->key);
    }
    void add(Node* node)
    {
        Node*temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        m[node->key]=node;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            Node* node=m[key];
            erase(node);
            add(node);
            
            return node->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            Node* temp=m[key];
            erase(temp);

        }
        if(m.size()==cap)
        {
            erase(tail->prev);
        }
        add(new Node(key,value));
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */