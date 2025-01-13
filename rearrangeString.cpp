#include <bits/stdc++.h> 
string rearrangeString(string &str) {
    int n=str.size();
    map<char,int>m;
    for(int i=0;i<n;i++)
    {
        m[str[i]]++;
    }
    priority_queue<pair<int,char>>pq;
    for(auto s:m)
    {
        pq.push({s.second,s.first});
    }
    string rearr;
    while(!pq.empty())
    {
        auto top=pq.top();
        char mostRecurred=top.second;
        int count=top.first;
        pq.pop();
        rearr+=mostRecurred;
        // cout<<mostRecurred<<" "<<count<<endl;
        // cout<<rearr<<endl;
        if(pq.empty() && count>1) return "NO SOLUTION";
        if(pq.empty() && count==1) return rearr;
        auto secondTop=pq.top();
        int count2=secondTop.first;
        pq.pop();
        rearr+=secondTop.second;
        if(count-1>0) pq.push({count-1,mostRecurred});
        if(count2-1>0)pq.push({count2-1,secondTop.second});
    }
    // cout<<rearr<<endl;
    return rearr;
    // Write your code here.
}
//time : O(nlogk)
//space: O(k)