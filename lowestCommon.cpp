/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode * getCommonAncestor(TreeNode* root, TreeNode* p , TreeNode *q)
    {
        if(root->val == p->val || root->val ==q->val) return root;
        else if(root->val<p->val && root->val > q->val) return root;
        else if(root->val > p->val && root->val < q->val) return root;
        else if(root->val>p->val && root->val >q->val)
        {
             return getCommonAncestor(root->left, p ,q);
        }
        else return getCommonAncestor(root->right,p,q);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return getCommonAncestor(root,p,q);
    }
};