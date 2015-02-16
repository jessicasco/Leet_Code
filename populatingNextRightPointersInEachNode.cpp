#include "leetcode.h"
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return ;
        }
        vector<TreeLinkNode*> stack;
        vector<TreeLinkNode*> next_level_stack;
        TreeLinkNode *previous = NULL;
        stack.push_back(root);
        while (!stack.empty()) {
            TreeLinkNode* p = stack.front();
            if (previous != NULL) {
                previous->next = p;
            }
            previous = p;
            stack.erase(stack.begin());
            if (p->left != NULL) {
                next_level_stack.push_back(p->left);
            }
            if (p->right != NULL) {
                next_level_stack.push_back(p->right);
            }
            if (stack.empty()) {
                p->next = NULL;
                stack = next_level_stack;
                next_level_stack.clear();
                previous = NULL;
            }
        }
    }
};
