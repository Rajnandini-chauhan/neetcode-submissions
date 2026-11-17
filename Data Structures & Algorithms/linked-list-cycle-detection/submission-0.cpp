/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Edge case: empty list or single node without a cycle
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Fast moves 2 steps, slow moves 1 step
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps
            
            // If they meet, there is a cycle
            if (slow == fast) {
                return true;
            }
        }
        
        // If fast reaches nullptr, the list has an end (no cycle)
        return false;
    }
};