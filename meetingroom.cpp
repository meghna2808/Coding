int Solution::solve(vector<vector<int> > &a) {
    int n=a.size();
    vector<int>start;
    vector<int>end;
    for(int i=0;i<n;i++)
    {
        start.push_back(a[i][0]);
        end.push_back(a[i][1]);   
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int i=0,j=0,count=0;
    int max_rooms=0;
    while(i<n && j<n)
    {
        if(start[i]<end[j])
        {
            i++;
            count++;
        }
        else
        {
            j++;
            count--;
        }
        max_rooms=max(max_rooms,count);
    }
    return max_rooms;
}
