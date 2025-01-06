int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++)
        {
            
            for(int j=1;j<=n;j++)
            {
                if(j<i)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j], price[i-1]+dp[i][j-i]);
                }
                
            }
           
        }
        
        return dp[n][n];
	// Write your code here.
}
