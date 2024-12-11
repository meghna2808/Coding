class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int products=1;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            products=products*nums[i];
        }
        vector<int>product;
        cout<<products<<endl;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==0)
            {
                int value=1;
                for(int j=0;j<size;j++)
                {
                    if(j==i) continue;
                    value=value*nums[j];
                }
                product.push_back(value);
                continue;
            }
            int val=products/nums[i];
            product.push_back(val);
        }
        return product;
    }
    
};
/* another approach*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int>prefix(size);
        prefix[0]=1;
        vector<int>suffix(size);
        suffix[size-1]=1;
        for(int i=1;i<size;i++)
        {
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int i=size-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]*nums[i+1];
        }
        vector<int>result(size);
        for(int i=0;i<size;i++)
        {
            result[i]=prefix[i]*suffix[i];
        }
        return result;
        
    }
};