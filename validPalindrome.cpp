class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        while(i<s.size())
        {
            if(s[i]>='A' && s[i]<='Z') 
            {
                i++;
                continue;
            }
            else if(s[i]>='a' && s[i]<='z' ||(s[i]>='0' && s[i]<='9')) 
            {
                i++;
                continue;
            }
            else 
            {
                s.erase(s.begin()+i);
            }
        }
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string s1=s;
        reverse(s1.begin(),s1.end());
        
        if(s==s1) return true;
        else return false;
        
    }
};