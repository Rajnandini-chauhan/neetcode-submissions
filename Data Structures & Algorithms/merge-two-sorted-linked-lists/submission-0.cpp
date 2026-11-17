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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // i am thinking of the approach i am going to create a dummy node and then assign the node with the -1;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr= dummy;

        while(list1!= nullptr && list2!=nullptr){
            // iterating through both linked list

            if(list1-> val<= list2->val){
                curr->next = list1;
                list1=list1->next;
            }else{
                curr->next = list2;
                list2=list2->next;
            }
            curr = curr->next;
        }

        // now i am going to consider a case if any linked list left

        if(list1!=nullptr){
            curr->next = list1;
        }else{
            curr->next = list2;
        }
        return dummy->next;
    }
};
