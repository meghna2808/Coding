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
    ListNode* reverse(ListNode* root, int k)
    {
        ListNode*prev=NULL;
        ListNode*next=NULL;
        ListNode*head=root;
        while(k>0 && head!=NULL)
        {
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
            k--;
        }
        root->next=next;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* root=head;
        while(root!=NULL)
        {
            count++;
            root=root->next;
        }
        int groups=count/k;
        ListNode* newhead=NULL;
        ListNode* newtail=NULL;
        ListNode*curr=head;
        while(groups>0)
        {
            ListNode*grouphead=reverse(curr,k);
            if(newhead==NULL)
            {
                newhead=grouphead;   
            }
            else newtail->next=grouphead;
            newtail=curr;
            curr=curr->next;
            groups--;

        }
        return newhead;
        
    }
};