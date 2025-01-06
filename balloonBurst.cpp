 int maxCoin(vector<int>& nums,int i , int j,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int ans=nums[i-1]*nums[k]*nums[j+1] + maxCoin(nums,i,k-1,dp)+maxCoin(nums,k+1,j,dp);
            maxi=max(maxi,ans);
        }
        return dp[i][j]=maxi;
    }
int burstBalloons(vector<int> &nums){
    int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return maxCoin(nums,1,n,dp);  
    // Write your code here.
}