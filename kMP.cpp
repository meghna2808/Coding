class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.size();
        int n=haystack.size();
        needle=" "+needle;
        int j=0,i=2;
        vector<int>pi(m+1,0);
        while(i<=m)
        {
            if(needle[j+1]==needle[i])
            {
                j++;
                pi[i]=j;
                i++;
            }
            else
            {
                if(j!=0)
                {
                    j=pi[j];
                }
                else i++;
            }
        }
        j=0,i=0;
        while(i<n)
        {
            if(needle[j+1]==haystack[i])
            {
                j++;
                i++;
                if(j==m) return i-j;
            }
            else
            {
                if(j!=0)
                {
                    j=pi[j];
                }
                else i++;
            }

        }  
        
        return -1;     
        
    }
};