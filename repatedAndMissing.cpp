int Solution::solve(vector<int> &a, int b) {
    int n=a.size();
    map<int,int>m;
    int count=0;
    int x=0;
    for(int i=0;i<n;i++)
    {
        x=x^a[i];
        if(x==b)count++;
        if(m.find(x^b)!=m.end())
        {
            count=count+m[x^b];
        }
        m[x]++;

    }
    return count;
}