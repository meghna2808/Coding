class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>nums;
        for(int i=0;i<n;i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int a=nums.top();
                nums.pop();
                int b=nums.top();
                nums.pop();
                if(tokens[i]=="+")
                {
                    nums.push(a+b);
                }
                else if(tokens[i]=="-")
                {
                    nums.push(b-a);
                }
                else if(tokens[i]=="/")
                {
                    nums.push(b/a);
                }
                else 
                {
                    nums.push(b*a);
                }
            }
            else nums.push(stoi(tokens[i]));
        }
        return nums.top();
        
    }
};