class Solution {
public:
    int minAddToMakeValid(string str) {
        int n=str.size();
        stack<int>s;
        s.push(str[0]);
        for(int i=1;i<n;i++)
        {
            if(!s.empty() && s.top()=='(')
            {
                if(str[i]==')')s.pop();
                else s.push(str[i]);
            }
            else s.push(str[i]);
        }
        int count=0;
        while(!s.empty())
        {
            s.pop();
            count++;
        }
        return count;

    }
};