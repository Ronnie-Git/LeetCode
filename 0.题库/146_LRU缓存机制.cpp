/*************************************************************************
	> File Name: 146_LRU缓存机制.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Sep 2020 06:32:04 PM CST
 ************************************************************************/

struct Node {
    int key;
    int value;
    Node *pre;
    Node *next;
    Node() : key{0}, value{0}, pre{nullptr}, next{nullptr} {}
    Node(int _key, int _value) : key{_key}, value{_value}, pre{nullptr}, next{nullptr} {}
};

class LRUCache {
private:
    unordered_map<int, Node *> m;
    int _size;
    int _capacity;
    Node *Head;
    Node *Tail;
public:
    LRUCache(int capacity) : _size{0}, _capacity{capacity}, Head{new Node{}}, Tail{new Node{}} {
        Head->next = Tail;
        Tail->pre = Head;
    }
    
    int get(int key) {
        if (!m.count(key)) return -1;
        Node *node = m[key];
        moveToHead(node);
        return node->value; 
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            Node *node = m[key];
            node->value = value;
            moveToHead(node);
            return ;
        }
        if (_size == _capacity) removeTail();
        Node *node = new Node{key, value};
        m[key] = node;
        addHead(node);
        ++ _size;
        return ;
    }

    void addHead(Node *node) {
        node->pre = Head;
        node->next = Head->next;
        Head->next->pre = node;
        Head->next = node;
        return ;
    }

    void moveToHead(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        addHead(node);
        return ;
    }

    void removeTail() {
        Node *delNode = Tail->pre;
        Tail->pre = delNode->pre;
        delNode->pre->next = Tail;
        m.erase(delNode->key);
        delete delNode;
        -- _size;
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
