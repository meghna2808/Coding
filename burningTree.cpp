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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>>neigh;
        queue<TreeNode*>q;
        unordered_map<int,bool>visited;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front =q.front();
            q.pop();
            if(front->left)
            {
                neigh[front->val].push_back(front->left->val);
                neigh[front->left->val].push_back(front->val);
                q.push(front->left);
                
            }
            if(front->right)
            {
                neigh[front->val].push_back(front->right->val);
                neigh[front->right->val].push_back(front->val);
                q.push(front->right);
            }
        }
        queue<int>qq;
        qq.push(start);
        visited[start]=true;
        int count=0;
        while(!qq.empty())
        {
            // count++;
            int n=qq.size();
            int flag=0;
            for(int i=0;i<n;i++)
            {
                int front=qq.front();
                qq.pop();
                for(auto j :neigh[front])
                {
                    if(visited[j]==false)
                    {
                        qq.push(j);
                        visited[j]=true;
                        // cout<<j<<" ";
                        flag=1;
                    }
                }
                
            }
            if(flag==1) count++;
            
        }
        return count;
        
    
        
    }
};