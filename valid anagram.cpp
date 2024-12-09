class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>frequency;
        for(int i=0;i<s.size();i++)
        {
            frequency[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(frequency.find(t[i])==frequency.end())
            {
                return false;
            }
            else
            {
                frequency[t[i]]--;
                if(frequency[t[i]]==0)
                {
                    frequency.erase(t[i]);
                }
            }
        }
        if(!frequency.empty()) return false;
        return true;
        
    }
};