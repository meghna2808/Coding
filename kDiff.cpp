bool check(string s, int k)
{
    int n=s.size();
    unordered_map<char,int>m;
    for(int i=0;i<n;i++)
    {
        m[s[i]]++;
        if(m.size()>k)return false;
    }
    if(m.size()==k)return true;
    return false;

}
int countSubStrings(string str, int k) 
{
    int n=str.size();
    int count=0;
    for(int i=0;i<=n-k;i++)
    {
        for(int j=k;j<=n-i;j++)
        {
            if(check(str.substr(i,j),k)==false) continue;
            else count++;
        }
    }
    return count;

    // Write your code here.
}
//sliding window approach