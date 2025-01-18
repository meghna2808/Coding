class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int>s;
        s.push(-1);
        int maxlen=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='(')
            {
                s.push(i);
            }
            else
            {
                s.pop();
                if(s.empty())
                {
                    s.push(i);
                }
                else maxlen=max(maxlen,i-s.top());
            }
        }
        return maxlen;
    }
};