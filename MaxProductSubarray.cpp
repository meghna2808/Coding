class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int size=arr.size();
	int max_product=INT_MIN;
	for(int i=0;i<size;i++)
	{
		int product=arr[i];
		max_product=max(max_product,product);
		for(int j=i+1;j<size;j++)
		{	
			product=product*arr[j];
			max_product=max(max_product,product);

		}
	}
	return max_product;
        
    }
}
/* alternative approach*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size=nums.size();
        int prefix=1,suffix=1;
        int max_product=INT_MIN;
        for(int i=0;i<size;i++)
        {
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix=prefix*nums[i];
            suffix=suffix*nums[size-1-i];
            max_product=max(max_product,max(prefix,suffix));
        }
        return max_product;
        
    }
};