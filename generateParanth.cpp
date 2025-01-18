class Solution {
public:
    vector<string>ans;
    void getParenth(int open , int close, int n, string s)
    {
        if(open+close==2*n)
        {
            ans.push_back(s);
            return ;
        }
        if(open<n)
        {
            getParenth(open+1,close,n,s+'(');
        }
        if(close<open)
        {
            getParenth(open,close+1,n,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        getParenth(0,0,n,"");
        return ans;
    }
};