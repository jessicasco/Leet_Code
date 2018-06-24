#include "leetcode.h"
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        Clone(head);
        CopyRandomPointer(head);
        return restore(head);
    }
    void Clone(RandomListNode *head) {
        while (head) {
            RandomListNode *clonedNode = new RandomListNode(head->label);
            clonedNode->next = head->next;
            head->next = clonedNode;
            head = clonedNode->next;
        }
    }
    void CopyRandomPointer(RandomListNode *head) {
        while (head) {
            RandomListNode *clonedNode = head->next;
            if (head->random) {
                clonedNode->random = head->random->next;
            }
            head = clonedNode->next;
        }
    }
    RandomListNode *restore(RandomListNode *head) {
        RandomListNode *pClonedHead = new RandomListNode(-1);
        RandomListNode *pClonedNode = pClonedHead;
        while (head) {
            pClonedNode->next = head->next;
            pClonedNode = pClonedNode->next;
            head->next = pClonedNode->next;
            head = head->next;
        }
        return pClonedHead->next;
    }
};
int main() {
    Solution s;
    RandomListNode *a = new RandomListNode(-1);
    RandomListNode *b = new RandomListNode(1);
    a->next = b;
    s.copyRandomList(a);
    return 0;
}