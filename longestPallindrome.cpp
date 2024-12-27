class Solution {
public:
    string longestPalindrome(string a) {
        int n=a.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        string ans="";
        int len=0;
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(gap==0)
                {
                    dp[i][j]=1;    
                }
                else if(gap==1)
                {
                    if(a[i]==a[j])
                    {
                        dp[i][j]=2;
                        
                    }
                    
                }
                else
                {
                    if(a[i]==a[j] && dp[i+1][j-1]!=0)
                    {
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                }
                // cout<<dp[i][j]<<endl;
                if(dp[i][j]>len)
                {
                    len=dp[i][j];
                    ans=a.substr(i,len);
                    // cout<<"hello"<<endl;
                }
            }
        }
        return ans;
        
    }
};