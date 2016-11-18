// 449. Serialize and Deserialize BST   QuestionEditorial Solution  My Submissions
// Total Accepted: 324
// Total Submissions: 763
// Difficulty: Medium
// Contributors: ben65
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
#include <iostream>
#include <string>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (root == NULL) {
            return std::string("");
        }

        std::string save_string{"t"};
        save_string.append(std::to_string(root->val));
        _m_iter_pre_order(root->left, false, save_string);
        _m_iter_pre_order(root->right, true, save_string);
        return save_string;
    }

    void _m_iter_pre_order(TreeNode *node, 
                        bool left_right, 
                        std::string &save_string) {
        if (node == NULL) {
            return;
        }

        if (!left_right) {
            save_string.append("l");
        }
        else {
            save_string.append("r");
        }

        save_string.append(std::to_string(node->val));

        _m_iter_pre_order(node->left, false, save_string);
        _m_iter_pre_order(node->right, true, save_string);
        save_string.append("b");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::stack<TreeNode*> node_holder;

        std::string::const_iterator index = data.cbegin();

        const char command = *(_m_get_command_data(data, index).cbegin());
        if (command != 't') {
            return NULL;
        }

        TreeNode *root = new TreeNode(std::stoi(_m_get_command_data(data, index)));
        TreeNode *visited_node = root;
        while(index != data.cend()) {
            const char command = *(_m_get_command_data(data, index).cbegin());
            switch(command) {
                case 'l' : node_holder.push(visited_node);
                           visited_node->left = new TreeNode(std::stoi(_m_get_command_data(data, index)));
                           visited_node = visited_node->left;
                           break;
                case 'r' : node_holder.push(visited_node);
                           visited_node->right = new TreeNode(std::stoi(_m_get_command_data(data, index)));
                           visited_node = visited_node->right;
                           break;
                case 'b' : visited_node = node_holder.top();
                           node_holder.pop();
                           break;
            }
        }

        return root;
    }

    std::string _m_get_command_data(std::string data, 
                                 std::string::const_iterator &index) {
        if (('a' <= *index) && (*index <= 'z')) {
            std::string return_string(index, index + 1);
            index++;
            return return_string;
        }

        std::string::const_iterator index_end = index + 1;
        while(index_end != data.cend() && is_digit(index_end)) {
            index_end++;
        }
        std::string return_string(index, index_end);
        index = index_end;
        return return_string;
    }

    bool is_digit(const std::string::const_iterator &index) {
        if ((*index >= '0') && (*index <= '9')) {
            return true;
        }
        if (*index == '-') {
            return true;
        }
        return false;
    }
};

TreeNode* make_random_tree(const int num_node);
void node_insert(TreeNode *root, const int val);
void print_tree_in_order(TreeNode* root);


int main(int argc, char const *argv[]) {
    TreeNode *root = make_random_tree(10);
    std::cout<<"The tree before:"<<std::endl;
    print_tree_in_order(root);
    std::cout<<std::endl;

    Codec codec;
    TreeNode *root2 = codec.deserialize(codec.serialize(root));

    std::cout<<"The tree after:"<<std::endl;
    print_tree_in_order(root2);
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
    std::cout<<"the current element is "<<root->val<<std::endl;
    print_tree_in_order(root->right);
}
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));