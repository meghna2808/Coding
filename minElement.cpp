class Solution {
public:
    int findMin(vector<int>& nums) {
        // vector<int>v=nums;
        // sort(v.begin(),v.end());
        int size=nums.size();
        // if(v==nums) return nums[0];
        bool asc=true,desc=true;
        if(size==1) return nums[0];
        if(size==2) return min(nums[0],nums[1]);
        for (int i=1;i<size-1;i++)
        {
            if(nums[i]<nums[i-1])
            {
                asc=false;
            }
            if(nums[i-1]<nums[i]) desc=false;
            if(nums[i-1]>nums[i] && nums[i+1]>nums[i]) return nums[i];
        }
        if(nums[size-1]<nums[size-2]) asc=false;
        if(nums[size-2]<nums[size-1])desc=false;
        if(asc==true) return nums[0];
        if(desc==true)return nums[size-1];
        else return min(nums[0],nums[size-1]);
        
        
        
    }
};