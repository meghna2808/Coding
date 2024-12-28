class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        int front;
        while(k>0)
        {
            front=pq.top();
            pq.pop();
            k--;

        }
        return front;
        
    }
};