#include <bits/stdc++.h> 
int closestCost(int N, int M, int X, vector<int> W, vector<int> G)
{
	int totalGift=pow(3,M);
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=0;i<totalGift;i++)
	{
		int temp=i;
		int sum=0;
		for(int j=0;j<M;j++)
		{
			int copies=temp%3;
			sum+=copies*G[j];
			temp=temp/3;
		}
		pq.push(sum);
	}
	// sort(W.begin(),W.end());
	int diff=INT_MAX;
	int ans=0;
	while(!pq.empty())
	{
		int top=pq.top();
		pq.pop();
		for(int i=0;i<N;i++)
		{
			int total_cost=top+W[i];
			if(abs(total_cost-X)<diff)
			{
				ans=total_cost;
				diff=abs(total_cost-X);
			}
			if(abs(total_cost-X)==diff)
			{
				if(total_cost<ans)ans=total_cost;
			}
		}

	}
	return ans;
	// Write your code here.
}