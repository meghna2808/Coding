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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>s;
        while(headA!=NULL)
        {
            s.insert(headA);
            headA=headA->next;
            
        }
        while(headB!=NULL)
        {
            if(s.find(headB)!=s.end())
            {
                return headB;
            }
            headB=headB->next;
        }
        return headB;
        
    }
};