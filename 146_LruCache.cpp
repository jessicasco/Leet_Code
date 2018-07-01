#include "leetcode.h"
struct node {
    int key, value;
    node *pre, *next;
    node(int k, int v): key(k),value(v),pre(NULL),next(NULL) {};
};

class LRUCache{
public:
    node *head, *tail;
    int capacity;
    int size;
    map<int, node*> m;
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0; 
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->pre = head;
        m.clear();
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            node *p = m[key];
            p->next->pre = p->pre;
            p->pre->next = p->next;
            p->next = head->next;
            head->next->pre = p;
            p->pre = head;
            head->next = p;
            return p->value;
        } else {
            return -1;
        }    
    }
    
    void set(int key, int value) {
       if (m.find(key) != m.end()) {
            node *p = m[key];
            p->next->pre = p->pre;
            p->pre->next = p->next;
            p->next = head->next;
            head->next->pre = p;
            p->pre = head;
            head->next = p;
            p->value = value;
       } else {
           node *p = new node(key, value);
           p->next = head->next;
           head->next->pre = p;
           p->pre = head;
           head->next = p;
           m[key] = p;
           size ++;
           if (size > capacity) {
               p = tail->pre;
               p->pre->next = tail;
               tail->pre = p->pre;
               m.erase(m.find(p->key));
               delete p;
               size --;
           }
       } 
    }
};
int main() {
    return 0;
}