// 160. Intersection of Two Linked Lists 
// Write a program to find the node at which the intersection of two singly linked lists begins.


// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// begin to intersect at node c1.


// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.

// 答案见图

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    bool a_reconnect = true;
    bool b_reconnect = true;
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode* index_a = headA;
        ListNode* index_b = headB;
        while (index_a != index_b && index_a && index_b) {
            index_a = index_a->next;
            index_b = index_b->next;
            
            if (!index_a && a_reconnect) {
                index_a = headB;
                a_reconnect = false;
            }
            
            if (!index_b && b_reconnect) {
                index_b = headA;
                b_reconnect = false;
            }
        }
       if (index_a) return index_a;
       return NULL;
    }
};