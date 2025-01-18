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
    vector<TreeNode*>ans;
    string  findDuplicates( TreeNode* root,unordered_map<string,int>&subTrees)
    {
        if(root==NULL) return "#";
        string left=findDuplicates(root->left,subTrees);
        string right=findDuplicates(root->right,subTrees);
        string s=left+","+right+","+to_string(root->val);
        if(subTrees[s]==1) ans.push_back(root);
        subTrees[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>subTrees;
        findDuplicates(root,subTrees);
        return ans;
    }
};