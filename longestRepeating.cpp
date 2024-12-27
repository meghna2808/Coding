class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>m;
        int n=s.size();
        int max_frequency=0;
        int j=0;
        int ans=1;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
            max_frequency=max(max_frequency,m[s[i]]);
            int len=i-j+1;
            if(len-max_frequency>k)
            {
                m[s[j]]--;
                j++;
            }
            else ans=max(ans,len);
        }
        return ans;
        
    }
};