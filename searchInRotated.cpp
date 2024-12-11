class Solution {
public:
    int search(vector<int>& nums, int target) {
        //brute force
        int size=nums.size();
        int ans=-1;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==target)return i;
        }
        return ans;
        
    }
};
/* binary search*/
class Solution {
public:
    int search(vector<int>& a, int target) {
        //brute force
        int size=a.size();
        int low=0,high=size-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(a[mid]==target) return mid;
            if(a[low]==target) return low;
            if(a[high]==target) return high;
            if(a[low]<=a[mid]) //left is sorted
            {
                if(a[low]<target && a[mid]>target)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if(a[mid]<target && a[high]>target)
                {
                    low=mid+1;
                }
                else
                {
                    high =mid-1;
                }
            }
        }
        return -1;
    }
};