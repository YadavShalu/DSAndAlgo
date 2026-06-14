/* Leetcode Link : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/  */

// Approach 1: Finding the Middle of the Linked List and Reversing the First half of the List
// --- Finding the middle of the linked list using the Floyd's Tortoise and Hare algorithm (slow and fast pointers).
// --- Reversing the first half of the linked list while finding the middle.
// --- After finding the middle, we will have two pointers: one at the head of the
// --- reversed first half and another at the middle (start of the second half).
// --- We will then calculate the twin sum by iterating through both halves simultaneously and updating the
// --- maximum twin sum encountered.

// Time Complexity: O(n) where n is the number of nodes in the linked list
// Space Complexity: O(1) 


class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next){
            fast = fast->next->next;
            swap(slow->next,prev);
            swap(prev,slow);
        }
        int res = 0;

        while(slow){
            res = max(res, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }
        return res;
    }
};


// Approach 2: Using a Stack to Store the First Half of the List
// --- We will use the Floyd's Tortoise and Hare algorithm to find the middle of the linked list.
// --- We will push the values of the first half of the linked list onto a stack.
// --- After finding the middle, we will have a pointer at the start of the second half of the linked list.
// --- We will then calculate the twin sum by popping values from the stack and adding them to

// Time Complexity: O(n) where n is the number of nodes in the linked list
// Space Complexity: O(n/2) = O(n) in the worst case, where n is the number of nodes in the linked list (if the list has an odd number of nodes).

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> half;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            half.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        int res = 0;
        int i = half.size() - 1;

        while (slow) {
            res = max(res, half[i--] + slow->val);
            slow = slow->next;
        }

        return res;
    }
};