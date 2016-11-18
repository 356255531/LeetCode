/* Delete note in a binary search tree
*/
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *target_node = _m_BST_Search(root, key);
        if (target_node == NULL) {
            return NULL;
        }

        TreeNode *node_to_be_deleted = (target_node->left == NULL ||
                                        target_node->right == NULL) ?
                                        target_node : 
                                        _m_SearchSuccessor(target_node);

        TreeNode *child_of_deleted_node = (node_to_be_deleted->left != NULL) ?
                                           node_to_be_deleted->left : 
                                           node_to_be_deleted->right;

        if (node_to_be_deleted == root) {
            if (node_to_be_deleted->left == NULL &&
                node_to_be_deleted->right == NULL) {
                delete(node_to_be_deleted);
                return target_node;
            }
            else {
                node_to_be_deleted->val = child_of_deleted_node->val;
                node_to_be_deleted->left = child_of_deleted_node->left;
                node_to_be_deleted->right = child_of_deleted_node->right;
                delete(child_of_deleted_node);
                return target_node;
            }
        }

        if (child_of_deleted_node == NULL) {
            TreeNode *parent_of_node_to_be_deleted = _m_FindParent(root, 
                                                node_to_be_deleted->val);
            delete(node_to_be_deleted);
            if (target_node == parent_of_node_to_be_deleted->left) {
                parent_of_node_to_be_deleted->left = NULL;
            }
            else {
                parent_of_node_to_be_deleted->right = NULL;
            }
            return target_node;
        }

        TreeNode *parent_of_node_to_be_deleted = _m_FindParent(root, 
                                                node_to_be_deleted->val);

        if (target_node == parent_of_node_to_be_deleted->left) {
            parent_of_node_to_be_deleted->left = child_of_deleted_node;
        }
        else {
            parent_of_node_to_be_deleted->right = child_of_deleted_node;
        }

        if (child_of_deleted_node != target_node) {
            target_node->val = node_to_be_deleted->val;
        }

        delete(node_to_be_deleted);
        return target_node;
    }

    TreeNode* _m_BST_Search(TreeNode *root, int key) {
        TreeNode *temp = root;
        while(temp->val != key && temp != NULL) {
            if (key < temp->val) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        return temp;
    }

    TreeNode* _m_SearchSuccessor(TreeNode *node) {
        if (node == NULL || node->right == NULL) {
            return NULL;
        }

        TreeNode *temp = node->right;
        while(temp != NULL) {
            temp = temp->left;
        }

        return temp;
    }

    TreeNode* _m_FindParent(TreeNode *root, int key) {
        if (root == NULL || root->val == key) {
            return NULL;
        }

        TreeNode *parent = root;
        while(1) {
            if (key < parent->val) {
                if (parent->left != NULL) {
                    if (parent->left->val == key) {
                        return parent;
                    }
                    else {
                        parent = parent->left;
                    }
                }
                else {
                    return NULL;
                }
            }
            else {
                if (parent->right != NULL) {
                    if (parent->right->val == key) {
                        return parent; 
                    }
                    else {
                        parent = parent->right;
                    }
                }
                else {
                    return NULL;
                }
            }
        }

        return parent;
    }
};

TreeNode* make_random_tree(const int num_node);
void node_insert(TreeNode *root, const int val);
void print_tree_in_order(TreeNode* root);


int main(int argc, char const *argv[]) {
    TreeNode *root = make_random_tree(10);
    print_tree_in_order(root);
    std::cout<<std::endl;

    Solution sl;
    sl.deleteNode(root, 9);

    print_tree_in_order(root);
    std::cout<<std::endl;
    return 0;
}

TreeNode* make_random_tree(const int num_node) {
    TreeNode *root = new TreeNode(0);
    for (int i = 1; i < num_node; ++i) {
        node_insert(root, i);       // Hier kann man zufallszahlen benutzen
    }
    return root;
}

void node_insert(TreeNode *root, const int val) {
    if (root == NULL) {
        std::cout<<"Empty tree in node node_insert"<<std::endl;
        return;
    }

    TreeNode *tree_index = root;
    while(tree_index != NULL) {
        if (tree_index->val == val) {
            std::cout<<"node already exists"<<std::endl;
        }

        if (val < tree_index->val) {
            if (tree_index->left != NULL) {
                tree_index = tree_index->left;
            }
            else {
                tree_index->left = new TreeNode(val);
                return;
            }
        }
        else {
            if (tree_index->right !=NULL) {
                tree_index = tree_index->right;
            }
            else {
                tree_index->right = new TreeNode(val);
                return;
            }
        }
    }
}

void print_tree_in_order(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    print_tree_in_order(root->left);
    std::cout<<"the current element is"<<root->val<<std::endl;
    print_tree_in_order(root->right);
}