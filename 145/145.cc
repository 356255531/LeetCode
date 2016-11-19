// Iterativly do post order Traversal


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <iostream>
 #include <vector>
 #include <stack>
 #include <set>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return std::vector<int>();
        }

        std::vector<int> output;

        std::stack<TreeNode*> node_stack;
        std::set<TreeNode*> visited_node;

        node_stack.push(root);
        visited_node.insert(root);

        while(!node_stack.empty()) {

            if (node_stack.top()->left != NULL) {
                const bool not_in = visited_node.find(node_stack.top()->left) == visited_node.end();
                if (not_in) {
                    visited_node.insert(node_stack.top()->left);
                    node_stack.push(node_stack.top()->left);
                    continue;
                }
            }
            if (node_stack.top()->right != NULL) { 
                const bool not_in = visited_node.find(node_stack.top()->right) == visited_node.end();
                if (not_in) {
                    visited_node.insert(node_stack.top()->right);
                    node_stack.push(node_stack.top()->right);
                    continue;
                }
            }
            output.push_back(node_stack.top()->val);
            node_stack.pop();
        }

        return output;
    }
};

int main(int argc, char const *argv[]) {
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left = new TreeNode(1);
    Solution sl;
    auto vec = sl.postorderTraversal(root);
    for(auto i = vec.cbegin(); i != vec.cend(); i++) {
        std::cout<<*i;
    }
    return 0;
}