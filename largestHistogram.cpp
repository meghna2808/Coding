class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        int max_area=INT_MIN;
        int i=0;
        for(;i<n;)
        {
            if(s.empty() || heights[i]>heights[s.top()])
            {
                s.push(i);
                i++;
            }
            else
            {
                int top=s.top();
                s.pop();
                if(s.empty())
                {
                    max_area=max(max_area,heights[top]*i);
                }
                else
                {
                    max_area=max(max_area,heights[top]*(i-s.top()-1));
                }

            }
        }
        while(!s.empty())
        {
            int top=s.top();
            s.pop();
            if(s.empty())
            {
                max_area=max(max_area,heights[top]*i);
            }
            else
            {
                max_area=max(max_area,heights[top]*(i-s.top()-1));
            }
        }
        return max_area;
        
    }
};