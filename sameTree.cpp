/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkSame(TreeNode*p, TreeNode*q)
    {
        if(p==NULL && q!=NULL) return false;
        if(q==NULL && p!=NULL) return false;
        if(p==NULL && q==NULL) return true;
        if(p->val!=q->val) return false;
        
        return checkSame(p->left,q->left) &&  checkSame(p->right , q->right);

    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkSame(p,q);
        
    }
};
//time : o(n)
/*space : Space Complexity Breakdown
	•	The recursion stack is the only additional space used by this solution.
	•	Best Case (Balanced Tree): Space complexity is O(log N) because the height of the tree determines the maximum depth of the stack.
	•	Worst Case (Skewed Tree): Space complexity is O(N) because the height of the tree can go up to N.
    he code doesn’t use any explicit extra data structures (like arrays or vectors). However, the implicit memory usage due to recursion is what contributes to the space complexity. */