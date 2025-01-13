class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        int mod=1000000007;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        while(k>0)
        {
            
            long long min_number=pq.top();
            min_number++;
            pq.pop();
            pq.push(min_number);
            k--;
        }
        long long  product=1;
        while(!pq.empty())
        {
            product=(product*pq.top())%mod;
            pq.pop();
        }
        return product%mod;
    }
};