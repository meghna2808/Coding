class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size=nums.size();
        set<int>s;
        s.insert(nums[0]);
        for(int i=1;i<size;i++)
        {
            if(s.find(nums[i])!=s.end())return true;
            else s.insert(nums[i]);
        }
        return false;
        
    }
};