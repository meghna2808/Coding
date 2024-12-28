class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        if(h<n) return -1;
        int max_val=INT_MIN;
        for(int i=0;i<n;i++)
        {
            max_val=max(max_val,piles[i]);
        }
        int left=1;
        int right=max_val;
        int min_val=max_val;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int count=0;
            for(int i=0;i<n;i++)
            {
                count+=ceil((double)piles[i]/mid);
                if(count>h) break;
            }
            
            if(count<=h)
            {
                min_val=min(mid,min_val);
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return min_val;
        
        
    }
};