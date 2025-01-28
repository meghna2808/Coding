class Solution {
public:
    int getFish(vector<vector<int>>&grid,int i , int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) return 0;
        int value=grid[i][j];
        grid[i][j]=0;
        int left=getFish(grid,i,j-1);
        int right=getFish(grid,i,j+1);
        int top=getFish(grid,i-1,j);
        int bottom=getFish(grid,i+1,j);
        return left+right+top+bottom+value;


    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int max_fish=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>0)
                {
                    int fish_collected=getFish(grid,i,j);
                    max_fish=max(max_fish,fish_collected);
                }
            }
        }
        return max_fish;
        
    }
};