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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* odd=head , *even=head->next;
        ListNode*ans=even;
        bool flag=false;
        ListNode*final= odd;
        while(even!=NULL && even->next!=NULL)
        {
            odd->next=odd->next->next;
            even->next=even->next->next;
            
            even=even->next;
            odd=odd->next;
        }
        odd->next=ans;
        return head;
        
    }
};