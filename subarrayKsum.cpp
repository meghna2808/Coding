class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefix_sum;
        int size=nums.size();
        int sum=0;
        map<int,int>m;
        for(int i=0;i<size;i++)
        {
            sum+=nums[i];
            prefix_sum.push_back(sum);
        }
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(prefix_sum[i]==k)
            {
                count++;
            }
            if(m.find((prefix_sum[i]-k))!=m.end())
            {
                count+=m[prefix_sum[i]-k];
            }
            m[prefix_sum[i]]++;
        }
        return count;
    }
};