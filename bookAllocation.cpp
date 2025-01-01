int countStudents(vector<int>&arr, int pages)
{
    int noStudents=1;
    int currentPages=0;
    for(int i=0;i<arr.size();i++)
    {
        if(currentPages+arr[i]<=pages)
        {
            currentPages=currentPages+arr[i];
        }
        else
        {
            noStudents++;
            currentPages=arr[i];
        }
    }
    return noStudents;
}
int findPages(vector<int>& arr, int n, int m) {
    // brute force approach
    if(m>n) return -1;
    int max_val=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        max_val=max(max_val,arr[i]);
        sum+=arr[i];
    }
    if(m==n) return max_val;
    int left=max_val, right=sum;
    // cout<<right<<endl;
    while(left<=right)
    {
        int mid=(left+right)/2;
        // cout<<mid<<endl;
        // if(countStudents(arr,mid)==m) return mid;
        if(countStudents(arr,mid)>m)
        {
            left=mid+1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}