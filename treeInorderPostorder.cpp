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
    TreeNode * build(vector<int>& inorder, vector<int>& postorder,int start , int end, int &index)
    {
        if(start>end) return NULL;
        int j;
        for(int i=end;i>=start;i--)
        {
            if(postorder[index]==inorder[i]) j=i;
        }
        index--;
        TreeNode* root=new TreeNode(inorder[j]);
        root->right=build(inorder,postorder,j+1,end,index);
        root->left=build(inorder,postorder,start,j-1,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int end=n-1;
        return build(inorder,postorder,0,n-1,end);
        
    }
};