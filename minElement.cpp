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
/* use binary search*/
class Solution {
public:
    int findMin(vector<int>& a) {
        int size=a.size();
        int left=0,right=size-1;
        if(a[left]<=a[right]) return a[left]; // sorted full array
        int min_val=INT_MAX;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(a[left]<=a[mid])// left part is sorted
            {
                min_val=min(min_val,a[left]);
                left=mid+1;
            }
            else
            {
                min_val=min(min_val,a[mid]);
                right=mid-1;
            }
        }
        return min_val;
    }
};