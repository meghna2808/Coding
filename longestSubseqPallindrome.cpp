class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        int len=0;
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;j++,i++)
            {
                if(gap==0)dp[i][j]=1;
                else if(gap==1)
                {
                    if(s[i]==s[j])dp[i][j]=2;
                    else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
                else if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                if(dp[i][j]>len)
                {
                    len=dp[i][j];
                }
            }
        }
        return len;
        
    }
};