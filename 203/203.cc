// 203. Remove Linked List Elements   QuestionEditorial Solution  My Submissions
// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }

        if (head->val == val) {
            auto temp = head->next;
            delete head;
            ListNode* return_node = removeElements(temp, val);
            return return_node;
        }
        
        auto index_val_previous = find_val_node(head, val);

        if (index_val_previous == NULL) {
            return head;
        }

        if (index_val_previous->next->next == NULL) {
            delete index_val_previous->next;
            index_val_previous->next = NULL;
        }
        else{
            auto temp = index_val_previous->next;
            index_val_previous->next = index_val_previous->next->next;
            delete temp;
        }

        ListNode* return_node = removeElements(head, val);

        return return_node;
    }
private:
    ListNode* find_val_node(ListNode* head, int val) {
        auto index = head;
        while(index->next != NULL) {
            if (index->next->val == val) {
                return index;
            }
            index = index->next;
        }
        return NULL;
    }
};