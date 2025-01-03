class Solution {
public:
    vector<vector<int>>ans;
    void calculateSubsets(int start, vector<int>&v, vector<int>& nums)
    {
        if(start==nums.size())
        {
            return ;
        }
        for(int i=start;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            ans.push_back(v);
            calculateSubsets(i+1,v,nums);
            v.pop_back();

        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        ans.push_back(v);
        calculateSubsets(0,v,nums);
        return ans;

        
    }
};