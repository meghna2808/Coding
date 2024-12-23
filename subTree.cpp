class Solution {
public:
    bool checkSame(TreeNode*root, TreeNode*subRoot)
    {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL && subRoot!=NULL) return false;
        if(root!=NULL && subRoot==NULL) return false;
        if(root->val!=subRoot->val) return false;
        return checkSame(root->left,subRoot->left) && checkSame(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL  && subRoot!=NULL) return false;
        if(root!=NULL && subRoot==NULL) return true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*front=q.front();
            q.pop();
            if(front->val==subRoot->val)
            {
                // cout<<front<<" "<<subRoot<<endl;
                if(checkSame(front,subRoot)) return true;;
            }
            if(front->left)
            {
                q.push(front->left);
            }
            if(front->right)
            {
                q.push(front->right);
            }
        }
        return false;
        
    }
};
// time : 0(n*m) n=nodes of main tree , m: nodes of subtree;
// space :O(m+n)