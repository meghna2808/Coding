class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int,int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
        int n=mat.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                }
                else mat[i][j]=INT_MAX;
            }
        }
        while(!q.empty())
        {
            auto front =q.front();
            q.pop();
            int row=front.first;
            int column=front.second;
            for (auto dirn : directions)
            {
                int newRow=row+dirn.first;
                int newCol=column+dirn.second;
                if(newRow>=0 && newRow<mat.size() && newCol>=0 && newCol<mat[0].size() && mat[newRow][newCol]>mat[row][column]+1) 
                {
                    mat[newRow][newCol]=mat[row][column]+1;
                    q.push({newRow,newCol});
                }
            }

        }
        return mat;

        
    }
};