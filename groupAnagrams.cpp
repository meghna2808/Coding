class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size=strs.size();
        map<string,vector<string>>m;
        for(int i=0;i<size;i++)
        {
            string str=strs[i];
            sort(str.begin(),str.end());
            m[str].push_back(strs[i]);
        }
        vector<vector<string>>anagrams;
        for(auto i:m)
        {
            vector<string>v;
            for(int j=0;j<i.second.size();j++)
            {
                v.push_back(i.second[j]);
            }
            anagrams.push_back(v);
        }
        return anagrams;
        
    }
};