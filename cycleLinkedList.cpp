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
    bool hasCycle(ListNode *head) {
        ListNode*curr=head;
        while(head!=NULL && curr!=NULL && curr->next!=NULL)
        {
            head=head->next;
            curr=curr->next->next;
            if(head==curr) return true;
        }
        return false;
        
    }
};