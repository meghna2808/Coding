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
    int count=0;
    pair<int,int> getSubtrees(TreeNode* root)
    {
        if(root==NULL) return {0,0};
        auto left=getSubtrees(root->left);
        auto right=getSubtrees(root->right);
        int subnodes=left.first+right.first+1;
        int sum=left.second+right.second+root->val;
        if(sum/subnodes==root->val) count++;
        return {subnodes,sum};
    }
    int averageOfSubtree(TreeNode* root) {
        getSubtrees(root);
        return count;
    }
};