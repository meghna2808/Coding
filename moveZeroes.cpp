class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
        int i=0,j=1;
        if(size==0 || size==1)  return ;
        while(j<size)
        {
            if(nums[j]!=0)
            {
                if(nums[i]==0)
                {
                    swap(nums[i],nums[j]);
                    j++;
                    i++;
                }
                else
                {
                    i++;
                    j++;
                }
                
            }
            else 
            {
                if(nums[i]!=0)i++;
                j++;
            }
        }

    }
};