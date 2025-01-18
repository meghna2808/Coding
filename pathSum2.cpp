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
    vector<vector<int>>ans;
    void getPath(TreeNode*root, int targetSum, vector<int>&temp,int sum)
    {
        if(root==NULL) return ;
        sum=sum+root->val;
        temp.push_back(root->val);
        if(root->right==NULL && root->left==NULL && sum==targetSum)
        {
            ans.push_back(temp);
        }
        getPath(root->left,targetSum,temp,sum);
        getPath(root->right,targetSum,temp,sum);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        getPath(root,targetSum,temp,0);
        return ans;
    }
};