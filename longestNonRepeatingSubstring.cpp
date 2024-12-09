class Solution {
public:
    int lengthOfLongestSubstring(string a) {
        int i=0,j=1;
        int size=a.size();
        if(size==0 || size==1) return size;
        
        map<char,int>m;
        int max_size=1;
        m[a[0]]=0;
        while(i<=j && j<size)
        {
            if(m.find(a[j])!=m.end())
            {

                i=m[a[j]]+1;
               for (auto it = m.begin(); it != m.end(); ) {
                if (it->second < i) {
                    it = m.erase(it);
                } else {
                    ++it;
                }
            }
                
                
            }
            max_size=max(max_size,j-i+1);
            m[a[j]]=j;
            j++;
        }
        return max_size;
        
    }
};