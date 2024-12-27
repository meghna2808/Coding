class Solution {
public:
    int countSubstrings(string a) {
        int n=a.size();
        vector<vector<bool>>dp(n, vector<bool>(n,false));
        int count=0;
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;j++,i++)
            {
                if(gap==0) 
                {
                    dp[i][j]=true;
                    count++;
                }
                else if(gap==1)
                {
                    if(a[i]==a[j])
                    {
                        dp[i][j]=true;
                        count++;
                    }
                }
                else
                {
                    if(a[i]==a[j]&& dp[i+1][j-1]==true)
                    {
                        dp[i][j]=true;
                        count++;
                    }
                }
            }
        }
        return count;

        
    }
};