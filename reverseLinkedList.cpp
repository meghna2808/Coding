class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newNode=NULL;
        while(head!=NULL)
        {
            ListNode* next=head->next;
            head->next=newNode;
            newNode=head;
            head=next;
        }
        return newNode;
        
    }
};
// time :O(n)
//space : O(1);