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
    void countNodes(TreeNode*root,vector<int>&nodes, int &max_val)
    {
        if(root==NULL) return ;
        
        nodes.push_back(root->val);
        if(max_val<=root->val) count++;
        max_val=max(max_val,root->val);
        countNodes(root->left,nodes,max_val);
        countNodes(root->right,nodes,max_val);
        if(nodes[nodes.size()-1]==max_val)
        {
            int value=INT_MIN;
            for(int i=0;i<nodes.size()-1;i++)
            {
                value=max(value,nodes[i]);
            }
            max_val=value;

        }
        nodes.pop_back();
        return ;
    }
    int goodNodes(TreeNode* root) {
        vector<int>nodes;
        countNodes(root,nodes,root->val);
        return count;
        
    }
};