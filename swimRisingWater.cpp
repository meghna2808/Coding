class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<pair<int,int>>drns{{-1,0},{1,0},{0,1},{0,-1}};
        int n=grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty())
        {
            auto front=pq.top();
            pq.pop();
            int depth=front[0];
            int x=front[1];
            int y=front[2];
            if(visited[x][y]==true)continue;
            visited[x][y]=true;
            if(x==n-1&& y==n-1)return depth;
            for(auto drn:drns)
            {
                int newx=x+drn.first;
                int newy=y+drn.second;
                if(newx>=0 && newy>=0 && newx<n && newy<n && visited[newx][newy]==false)
                {
                    pq.push({max(grid[newx][newy],depth),newx,newy});
                }
            }
        }
        return 0;
        
    }
};