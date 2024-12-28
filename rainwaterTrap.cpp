class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int max_val=INT_MIN;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            max_val=max(max_val,height[i]);
            v.push_back(max_val);
        }
        max_val=INT_MIN;
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            max_val=max(max_val,height[i]);
            v[i]=min(v[i],max_val);
            if(height[i]<v[i])
            {
                count+=v[i]-height[i];

            }
        }
        return count;
        
    }
};