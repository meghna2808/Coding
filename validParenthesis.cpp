class Solution {
public:
    bool isValid(string a) {
        int n=a.size();
        stack<char>s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                if(a[i]==')' || a[i]==']' || a[i]=='}')
                {
                    return false;
                }
                else s.push(a[i]);
            }
            else
            {
                char top=s.top();
                if((a[i]==')' && top=='(') || (a[i]==']' && top=='[') || (a[i]=='}' && top=='{') )
                {
                    s.pop();
                }
                else
                {
                    s.push(a[i]);
                }
            }
        }
        if(s.empty()) return true;
        else return false;
        
    }
};