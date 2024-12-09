class Solution {
public:
    string reverseVowels(string s) {
        int size=s.size();
        int i=0;
        vector<char>v;
        for(int i=0;i<size;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o' || s[i]== 'u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                // cout<<s[i]<<endl;
                v.push_back(s[i]);
            }
        }
        int j=v.size()-1;
        for(int i=0;i<size;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o' || s[i]== 'u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                s[i]=v[j];
                j--;
            }
        }
        return s;
 
        
    }
};