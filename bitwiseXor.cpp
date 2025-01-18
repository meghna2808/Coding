class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        //lets start with 1;
        vector<int>bit(n,0);
        bit[0]=1;
        int same=true;
        if(derived[0]==1)same=false;
        for(int i=1;i<n;i++)
        {
            if(same==false)
            {
                if(bit[i-1]==1)bit[i]=0;
                else bit[i]=1;
            }
            else
            {
                if(bit[i-1]==0)bit[i]=0;
                else bit[i]=1;
            }

            if(derived[i]==1)
            {
                same=false;
            }
            else same =true;
        }
        if(same==false)
        {
            if(bit[n-1]!=bit[0]) return true;
        }
        else 
        {
            if(bit[n-1]==bit[0]) return true;
        }
        bit[0]=0;
        same=false;
        if(derived[0]==0)same=true;
        for(int i=1;i<n;i++)
        {
            if(same==false)
            {
                if(bit[i-1]==1)bit[i]=0;
                else bit[i]=1;
            }
            else
            {
                if(bit[i-1]==0)bit[i]=0;
                else bit[i]=1;
            }

            if(derived[i]==1)
            {
                same=false;
            }
            else same =true;
        }
        if(same==false)
        {
            if(bit[n-1]!=bit[0]) return true;
        }
        else 
        {
            if(bit[n-1]==bit[0]) return true;
        }
        return false;
        
    }
};