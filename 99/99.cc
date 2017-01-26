// 99. Recover Binary Search Tree

// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

// 中序遍历二叉树，出现的节点的值会升序排序，如果有两个节点位置错了，那肯定会出现降序。
// 设置一个pre节点指针，记录当前节点中序遍历时的前节点，如果当前节点小于pre节点的值，说明需要调整次序。
// 如果在中序遍历时节点值出现了两次降序，第一个错误的节点为第一次降序时较大的节点，第二个错误节点为第二次降序时较小的节点。
// 如，原来的搜索二叉树在中序遍历的节点值依次为{1,2,3,4,5}，如果因为两个节点位置错了而出现{1,5,3,4,2}，
// 第一次降序为5->3，所以第一个错误节点为5，第二次降序为4->2,所以第二个错误节点为2，将5和2换过来就可以恢复。
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* swaped_node_1 = NULL;
    TreeNode* swaped_node_2 = NULL;
    TreeNode* prev = NULL;

public:
    void recoverTree(TreeNode* root) {
        if (not root) {
            return;
        }

        find_swaped_node(root);

        std::swap(swaped_node_1->val, swaped_node_2->val);
    }
    void find_swaped_node(TreeNode* node) {
        if (node->left) {
            find_swaped_node(node->left);
        }

        if (prev and prev->val > node->val) {
            if (swaped_node_1) {
                swaped_node_2 = node;
            }
            else {
                swaped_node_1 = prev;
                swaped_node_2 = node;
            }
        }

        prev = node;

        if (node->right) {
            find_swaped_node(node->right);
        }
    }

};

int main(int argc, char const *argv[]) {
    TreeNode* root = new TreeNode(2);TreeNode* left_child = new TreeNode(3);//TreeNode* right_child = new TreeNode(1);
    root->left = left_child;//root->right = right_child;
    Solution* sl = new Solution;
    std::cout<<left_child->val<<root->val<<std::endl;
    sl->recoverTree(root);
    std::cout<<left_child->val<<root->val<<std::endl;
    return 0;
}