#include <bits/stdc++.h> 
bool subsetSumToK(int n, int target, vector<int> &arr) {
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                // cout<<
                if(j<arr[i-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j]|| dp[i-1][j-arr[i-1]];
                    
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return dp[n][target];
}