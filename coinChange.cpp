class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int size=coins.size();
        vector<vector<int>>dp(size+1,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<=size;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=size;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(j<coins[i-1] || dp[i][j-coins[i-1]]==INT_MAX )dp[i][j]=dp[i-1][j];
                else dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
        }

        if(dp[size][amount]==INT_MAX) return -1;
        else return dp[size][amount];
        
    }
};