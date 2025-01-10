class Solution {
public:
    int getIslands(vector<vector<int>>& grid,int i , int j ,vector<vector<bool>>&visited )
    {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || visited[i][j]==true || grid[i][j]==0)
        {
            return 0;
        }
        visited[i][j]=true;
        int left=getIslands(grid,i-1,j,visited);
        int right=getIslands(grid,i+1,j,visited);
        int top=getIslands(grid,i,j-1,visited);
        int bottom =getIslands(grid,i,j+1,visited);
        return 1+left+right+top+bottom;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int max_area=0;
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==false)
                {
                    max_area=max(max_area, getIslands(grid,i,j,visited));
                }
            }
        }
        return max_area;
        
    }
};