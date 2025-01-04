class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        while(i<s.size() && g[0]>s[i])
        {
            i++;

        }
        int count=0;
        int j=0;
        while(i<s.size() && j<g.size())
        {
            if(s[i]>=g[j])
            {
                count++;
                j++;
            }
            i++;
        }
        return count;
        
    }
};