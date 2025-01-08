struct Node{
    Node* link[26];
    bool contains(char ch)
    {
        return link[ch-'a']!=NULL;
    }
    void put(char ch , Node* node)
    {
        link[ch-'a']=node;
    }
    Node* get (char ch)
    {
        return link[ch-'a'];
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
    int getCount(char ch,Node* node)
    {
        if(node->contains(ch)) return 0;
        node->put(ch,new Node);
        return 1;
    }
    int getSubstrings(string s)
    {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            Node* node=root;
            for(int j=i;j<n;j++)
            {
                count+=getCount(s[j],node);
                node=node->get(s[j]);
            }
        }
        return count+1;

    }
};
int countDistinctSubstrings(string &s)
{
    Trie* obj= new Trie();
    return obj->getSubstrings(s);
    //    Write your code here.
}