class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size();
        int left=0;
        int right=size-1;
        int max_height=INT_MIN;
        while(left<right)
        {
            max_height=max(max_height,min(height[right],height[left])*(right-left));
            if(height[left]<height[right])
            {
                left++;
            }
            else if(height[right]<height[left])
            {
                right--;
            }
            else
            {
                right--;
                left++;
            }
        }
        return max_height;
    }
};