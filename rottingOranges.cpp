class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>>dirn={{-1,0},{1,0},{0,-1},{0,1}};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }

        }
        int time=0;
        while(!q.empty())
        {
            int size=q.size();
            time++;
            for(int i=0;i<size;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto dir:dirn)
                {
                    int newx=x+dir.first;
                    int newy=y+dir.second;
                    if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1)
                    {
                        grid[newx][newy]=2;
                        q.push({newx,newy});
                    }
                    
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return max(0,time-1);

        
    }
};