class Solution {
public:
    int squareOfDigits(int n)
    {
        vector<int>v;
        while(n>0)
        {
            v.push_back(n%10);
            n=n/10;
        }
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=(v[i]*v[i]);
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int>s;
        s.insert(n);
        if(n==1) return true;
        while(n!=1)
        {
            n=squareOfDigits(n);
            if(s.find(n)!=s.end()) return false;
            s.insert(n);
        }
        return true;
        
    }
};