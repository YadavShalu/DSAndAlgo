/* Leetcode Link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/  */

// Approach 1: 
// --- We will use Floyd's Tortoise and Hare algorithm to find the middle of the linked list.
// --- We will keep track of the previous node of the slow pointer to delete the middle node.


// Time Complexity: O(n) where n is the number of nodes in the linked list
// Space Complexity: O(1) 


struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution{
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = slow->next;
        delete slow;
        return head;
    }
};