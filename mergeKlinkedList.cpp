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
    ListNode* sort(ListNode* list1, ListNode* list2)
    {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val<=list2->val)
        {
            list1->next=sort(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next=sort(list1,list2->next);
            return list2;
        }
        //  ListNode*ans=new ListNode(-1);
        // ListNode* mergedList=ans;
        // // int flag=0;
        // while(list1!=NULL && list2!=NULL)
        // {
            
        //         if(list1->val<=list2->val)
        //         {
        //             mergedList->next=new ListNode(list1->val);
        //             mergedList=mergedList->next;
        //             list1=list1->next;
        //         }
        //         else
        //         {
        //             mergedList->next = new ListNode(list2->val);
        //             mergedList=mergedList->next;
        //             list2=list2->next;
        //         }

        // }
        // while(list1!=NULL)
        // {
        //     mergedList->next= new ListNode(list1->val);
        //     mergedList=mergedList->next;
        //     list1=list1->next;
        // }
        // while(list2!=NULL)
        // {
        //     mergedList->next= new ListNode(list2->val);
        //     mergedList=mergedList->next;
        //     list2=list2->next;
        // }
        // return ans->next;
    }
    ListNode* divide(vector<ListNode*>& lists , int start , int end)
    {
        if(start==end) return lists[start];
        int mid =start+(end-start)/2;
        ListNode*l1=divide(lists,start,mid);
        ListNode*l2=divide(lists,mid+1,end);
        return sort(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        return divide(lists,0,n-1);
        
    }
};
/*Time Complexity: O(N log k)
( N ): Total number of nodes across all lists.
( log k ): Number of levels in the divide-and-conquer recursion tree.
Space Complexity: O(log k) due to recursive function calls.*/