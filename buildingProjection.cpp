#include <bits/stdc++.h> 
int projectionArea(vector<vector<int>> &grid) {
    int xy_plane=0;
    int yz_plane=0;
    int xz_plane=0;
    int n=grid.size();
    for(int i=0;i<n;i++)
    {
        
        int max_height=0;
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]!=0) xy_plane++;
            max_height=max(max_height,grid[i][j]);
        }
        yz_plane+=max_height;
    }
    for(int j=0;j<n;j++)
    {
        int max_height=0;
        for(int i=0;i<n;i++)
        {
            max_height=max(max_height,grid[i][j]);
        }
        xy_plane+=max_height;
    }
    return xy_plane+xz_plane+yz_plane;
    // Write your code here. 
}