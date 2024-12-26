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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second_half=slow->next;
        slow->next=NULL;
        ListNode* head2=NULL;
        while(second_half!=NULL)
        {
            ListNode* next=second_half->next;
            second_half->next=head2;
            head2=second_half;
            second_half=next;
        }
        ListNode* first_half=head;
        second_half=head2;
        while(second_half!=NULL && first_half!=NULL)
        {
            ListNode* temp1=first_half->next;
            ListNode*temp2=second_half->next;
            first_half->next=second_half;
            second_half->next=temp1;
            first_half=temp1;
            second_half=temp2;
        }
        
    }
};