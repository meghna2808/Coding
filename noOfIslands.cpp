class Solution {
public:
    void traverseIslands(vector<vector<char>>& grid, int i , int j,vector<vector<bool>>&visited)
    {
        int rows=grid.size();
        int columns=grid[0].size();
        if(i<0 || i>=rows|| j<0 || j>=columns || grid[i][j]=='0' || visited[i][j]==true) return ;
        visited[i][j]=true;
        traverseIslands(grid,i+1,j,visited);
        traverseIslands(grid,i,j+1,visited);
        traverseIslands(grid,i-1,j,visited);
        traverseIslands(grid,i,j-1,visited);
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int columns=grid[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(columns,false));
        int islands=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==false)
                {
                    traverseIslands(grid,i,j,visited);
                    islands++;
                }
            }
        }
        return islands;
        
    }
};