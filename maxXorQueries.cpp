struct Node{
    Node* link[2];
    bool contains(int bit)
    {
        return link[bit]!=NULL;
    }
    void put(int bit, Node* node)
    {
        link[bit]=node;
    }
    Node* get(int bit)
    {
        return link[bit];
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int bit =num>>i & 1;
            if(!node->contains(bit))
            {
                node->put(bit, new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num)
    {
        Node* node=root;
        if(node==NULL) return -1;
        int max_xor=0;
        for(int i=31;i>=0;i--)
        {
            int bit=num>>i & 1;
            // if(node==NULL) break;
            if(node->contains(1-bit))
            {
                max_xor=max_xor | 1<<i;
                node=node->get(1-bit);
            }
            else node= node->get(bit);
        }
        return max_xor;
    }

};
class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        Trie* obj=new Trie();
        for(int i=0;i<n;i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),compare);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            cout<<queries[i][0]<<" "<<queries[i][1]<<" "<<queries[i][2]<<endl;
        }
        int m=nums.size();
        int j=0;
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            while(j<m && nums[j]<=queries[i][1])
            {
                obj->insert(nums[j]);
                j++;
            }
            if(j==0) ans[queries[i][2]]=-1;
            else ans[queries[i][2]]=obj->getMax(queries[i][0]);
        }
        return ans;
    }
};