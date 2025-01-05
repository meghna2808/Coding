int ninjaTraining(int n, vector<vector<int>> &arr)
{
     vector<vector<int>>dp(n,vector<int>(3,0));
        for(int i=0;i<3;i++)
        {
            dp[0][i]=arr[0][i];
            
        }
        for(int i=1;i<n;i++)
        {
            dp[i][0]=arr[i][0]+max(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=arr[i][1]+max(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=arr[i][2]+max(dp[i-1][0],dp[i-1][1]);
        }
        
        return max(dp[n-1][0],max(dp[n-1][2],dp[n-1][1]));
    // Write your code here.
}