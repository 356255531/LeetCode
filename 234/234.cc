// 234. Palindrome Linked List 
// Given a singly linked list, determine if it is a palindrome.

// Follow up:
// Could you do it in O(n) time and O(1) space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        if (!head->next) return true;

        ListNode* middle = find_middle(head);
        
        ListNode* index_x = head;
        ListNode* index_y = reverse_list(middle);
        while (index_x && index_y) {
            if (index_x->val != index_y->val) return false;
            index_x = index_x->next;
            index_y = index_y->next;
        }
        reverse_list(middle);
        return true;
    }
    
    ListNode* find_middle(ListNode* head) {
        if (!head) return head;
        ListNode* prev = head;
        ListNode* latter = head;
        
        while (latter && latter->next) {
            prev = prev->next;
            latter = latter->next->next;
        }
        return prev;
    }
    ListNode* reverse_list(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = head->next;
        while (temp->next) {
            curr->next = prev;
            prev = curr;
            curr = temp;
            temp = temp->next;
        }
        curr->next = prev;
        temp->next = curr;
        return temp;
    }
};