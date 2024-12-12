//brute force approach
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int size=gifts.size();
        sort(gifts.begin(),gifts.end());
        for(int i=0;i<k;i++)
        {
            int max_val=gifts[size-1];
            gifts[size-1]=sqrt(max_val);
            sort(gifts.begin(),gifts.end());
        }
        long long no_gifts=0;
        for(int i=0;i<size;i++)
        {
            no_gifts+=gifts[i];
        }
        return no_gifts;
        
    }
};
// using priority queue
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq(gifts.begin(),gifts.end());
        long long  sum=0;
        for(int i=0;i<k;i++)
        {
            int top=pq.top();
            pq.pop();
            top=sqrt(top);
            pq.push(top);
        }
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();

        }
        return sum;
        
    }
};