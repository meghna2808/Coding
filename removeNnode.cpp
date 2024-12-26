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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0 , size=0;
        ListNode* newNode=head, *head2=head;
        while(head2!=NULL)
        {
            size++;
            head2=head2->next;
        }
        n=size-n;
        if(n==0) return head->next;
        while(head!=NULL)
        {
            
            if(count==n-1)
            {
                head->next=head->next->next;
            }
            count++;
            head=head->next;

        }
        return newNode;
        
    }
};