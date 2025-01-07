class Solution {
public:
    int mod = 1000000;
    int robin_karp(string source, string pattern)
    {
        int m=pattern.size();
        int power=1;
        for(int i=0;i<m;i++)
        {
            power=(31*power)%mod;
        }
        int patternCode=0;
        for(int i=0;i<m;i++)
        {
            patternCode=(patternCode*31+pattern[i]-'a'+1)%mod;
        }
        int hashCode=0;
        for(int i=0;i<source.size();i++)
        {
            hashCode=(hashCode*31+(source[i]-'a'+1))%mod;
            if(i<m-1)continue;
            if(i>=m)
            {
                hashCode=(hashCode-(source[i-m]-'a'+1)*power)%mod; 
            }
            if(hashCode<0) hashCode+=mod;
            if(hashCode==patternCode)
            {
                if(source.substr(i-m+1,m)==pattern)return i-m+1;
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        int count=1;
        string source=a;
        while(a.size()<b.size())
        {
            count++;
            a+=source; 
        }
        if(robin_karp(a,b)!=-1) return count;
        if(robin_karp(a+source,b)!=-1)return count+1;
        return -1;
        
    }
};