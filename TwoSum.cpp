/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<size;i++)
        {
            if(target-nums[i]==nums[i])
            {
                if(m.find(nums[i])!=m.end())
                {
                    return {m[nums[i]],i};
                }
            }
            else
            {
                if(m.find(target-nums[i])!=m.end())
                {
                    return {m[target-nums[i]],i};
                }
            }
            m[nums[i]]=i;
        }
        return {0,0};
        
    }
};