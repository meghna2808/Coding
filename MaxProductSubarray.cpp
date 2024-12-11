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
};