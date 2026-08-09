class LRUCache {
private:
    // Doubly Linked List for O(1) insertion and removal
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode* prev;

        ListNode(pair<int, int> c)
            : key(c.first), val(c.second), prev(nullptr), next(nullptr) {}
        ListNode(pair<int, int> c, ListNode* p, ListNode* n)
            : key(c.first), val(c.second), prev(p), next(n) {}
    };
    // Stores the actual key-value pair for O(1) retrieval
    unordered_map<int, ListNode*> mp;

    ListNode* head;
    ListNode* tail;

    int capacity;

    void addNodeToHead(pair<int, int> cache) {
        auto oldNext = head->next;

        ListNode* newNode = new ListNode(cache, head, oldNext);

        head->next = newNode;

        oldNext->prev = newNode;

        mp.insert({newNode->key, newNode});
    }

    void deleteNodeAtTail() {
        auto oldNode = tail->prev;
        auto prev = oldNode->prev;

        prev->next = tail;
        tail->prev = prev;

        mp.erase(oldNode->key);
        delete oldNode;
    }

    void moveNodeToHead(ListNode* node) {
        // remove the old connection
        auto prev = node->prev;
        auto next = node->next;

        prev->next = next;
        next->prev = prev;

        // add the new connection
        auto oldNext = head->next;

        head->next = node;
        node->next = oldNext;

        oldNext->prev = node;
        node->prev = head;
    }
    void moveNodeToHead(ListNode* node, int newValue) {
        node->val = newValue;
        moveNodeToHead(node);
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        // initialize dummy head and tail node
        head = new ListNode({-1, -1});
        tail = new ListNode({-1, -1}, head, nullptr);
        head->next = tail;
    }

    ~LRUCache() {
        // cleanup head and tail from heap
        delete head;
        delete tail;
    }

    int get(int key) {
        if (!mp.contains(key)) {
            return -1;
        }

        ListNode* ansNode = mp[key];
        // just move the node from it's original position to MRU
        moveNodeToHead(ansNode);

        return ansNode->val;
    }

    void put(int key, int value) {
        if (mp.contains(key)) {
            ListNode* existingNode = mp[key];
            // just move the node from it's original position to MRU
            moveNodeToHead(existingNode, value);
            return;
        }

        if (mp.size() == capacity) {
            // If capacity is full, delete LRU
            deleteNodeAtTail();
        }

        // Append new node to MRU
        addNodeToHead({key, value});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */