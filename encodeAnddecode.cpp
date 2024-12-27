class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        vector<int>size;
        string result;
        for(int i=0;i<n;i++)
        {
           result+=to_string(strs[i].size())+"#"+strs[i];
        }
        return result;

    }

    vector<string> decode(string s) {
        int i=0;
        vector<string>decoded;
        while(i<s.size())
        {
            int j=i;
            while(s[j]!='#')
            {
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            i=j+1;
            j=i+len;
            decoded.push_back(s.substr(i,len));
            i=j;

        }
        return decoded;

    }
};
