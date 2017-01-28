#include <iostream>
#include <vector>
#include <set>
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
    std::set<TreeNode*> visited;
    std::vector<TreeNode*> path;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find_node(root, p);
        std::vector<TreeNode*> path_1(path);
        path.clear();
        visited.clear();
        find_node(root, q);
        std::vector<TreeNode*> path_2(path);
        int min_size = path_1.size() < path_2.size()? path_1.size() : path_2.size();
        TreeNode* common_node = path_1[0];
        for(int i = 0; i < min_size;i++) {
            if (path_1[i] == path_2[i]) common_node = path_1[i];
        }
        return common_node;
        
    }
    bool find_node(TreeNode* root, TreeNode* node) {
        if (!root) return false;
        path.push_back(root);
        visited.insert(root);
        if (root->val == node->val) {
            return true;
        }

        if (root->left){
            if (visited.find(root->left) == visited.end()) {
                if (find_node(root->left, node)) {
                    return true;
                }
            }
        }

        if (root->right){
            if (visited.find(root->right) == visited.end()) {
                if (find_node(root->right, node)) {
                    return true;
                }
            }
        }

        path.erase(path.end() - 1);
        return false;
        
    }
};

int main(int argc, char const *argv[]) {
    TreeNode* a = new TreeNode(5);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(6);
    TreeNode* d = new TreeNode(2);
    TreeNode* e = new TreeNode(4);
    TreeNode* f = new TreeNode(1);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    d->left = f;
    Solution sl;
    std::cout<<sl.lowestCommonAncestor(a, e, f)->val<<std::endl;
    return 0;
}