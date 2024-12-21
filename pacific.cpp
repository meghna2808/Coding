class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>&visited, int row, int column)
    {
        visited[row][column]=true;
        if(row<heights.size()-1 && visited[row+1][column]==false && heights[row+1][column]>=heights[row][column])
        {
            dfs(heights,visited,row+1,column);
        }
        if(row>0 && visited[row-1][column]==false && heights[row-1][column]>=heights[row][column])
        {
            dfs(heights,visited,row-1,column);
        }
        if(column>0 && visited[row][column-1]==false && heights[row][column-1]>=heights[row][column])
        {
            dfs(heights,visited,row,column-1);
        }
        if(column<heights[0].size()-1 && visited[row][column+1]==false && heights[row][column+1]>=heights[row][column])
        {
            dfs(heights,visited,row,column+1);
        }
        return ;

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int columns=heights[0].size();
        vector<vector<int>>results;
        vector<vector<bool>>reach_pacific(row,vector<bool>(columns,false));
        vector<vector<bool>>reach_atlantic(row,vector<bool>(columns,false));
        for(int i=0;i<row;i++)
        {
            dfs(heights,reach_pacific,i,0);
            dfs(heights,reach_atlantic,i,columns-1);

        }
        for(int j=0;j<columns;j++)
        {
            dfs(heights,reach_pacific,0,j);
            dfs(heights,reach_atlantic,row-1,j);

        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(reach_pacific[i][j] && reach_atlantic[i][j])
                {
                    results.push_back({i,j});
                }
            }
        }
        return results;
        
    }
};

// link https://leetcode.com/problems/pacific-atlantic-water-flow/solutions/6172037/c-solution-graph-by-msy2808-8i6m
