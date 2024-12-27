class Solution {
public:
    string convertToString(int y)
    {
        string s="";
        while(y>0)
        {
            int b=y%10;
            s+=(b-'0');
            y=y/10;
        }
        
        reverse(s.begin(),s.end());
        return s;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s=convertToString(x);
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-1-i]) return false;
        }
        return true;
        
    }
};