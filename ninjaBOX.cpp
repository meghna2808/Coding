#include <bits/stdc++.h> 

int ninjaAndBoxStack(vector<int>& length, vector<int>& breadth, vector<int>& height, int n) 
{
	vector<vector<int>>allCombinations;
	// int n=length.size();
        for (int i = 0; i < n; i++) {
                allCombinations.push_back({
      max(length[i], breadth[i]), min(length[i], breadth[i]), height[i]});
	  allCombinations.push_back({max(breadth[i],height[i]),min(breadth[i],height[i]),length[i]});
	  allCombinations.push_back({max(length[i],height[i]),min(length[i],height[i]),breadth[i]});
        }
		int m=allCombinations.size();
		sort(allCombinations.begin(),allCombinations.end(),[](vector<int>&a, vector<int>&b){
			return a[0]*a[1]>b[0]*b[1];
		});
	vector<int>dp(m,0);
	for(int i=0;i<m;i++)
	{
		dp[i]=allCombinations[i][2];
	}
	int max_height=dp[0];
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(allCombinations[j][0]>allCombinations[i][0] && allCombinations[j][1]>allCombinations[i][1] )
			{
				dp[i]=max(dp[i],dp[j]+allCombinations[i][2]);
			
			}
		}
		max_height=max(max_height,dp[i]);
	}
	return max_height;
        
}
	// Write your code here.
