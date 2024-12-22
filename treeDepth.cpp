class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int height=0;
        //using bfs traversal
        while(!q.empty())
        {
            height++;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
        }
        return height;
        
    }
};