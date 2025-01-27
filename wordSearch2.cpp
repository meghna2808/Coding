struct Node{
    Node* links[26];
    bool flag=false;

    bool contains(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch , Node* node)
    {
        links[ch-'a']=node;
    }
    void setFlag(bool value){
        flag=value;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    bool getFlag()
    {
        return flag;
    }
};
class Trie{
    public:
    Node* root;
    Trie()
    {
        root=new Node();
    }
    void insert(string word)
    {
        Node * node=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(!node->contains(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setFlag(true);
    }
};
class Solution {
public:
    vector<string>ans;
    void dfs(vector<vector<char>>& board, int i , int j , Node* root, string s)
    {
        int n=board.size();
        int m=board[0].size();
        if(i>=n || j>=m || i<0 || j<0 || board[i][j]=='*' || !root->contains(board[i][j])) return ;
        s+=board[i][j];
        Node*temp=root->get(board[i][j]);
        if(temp->getFlag())
        {
            ans.push_back(s);
            temp->setFlag(false);
        }
        char ch =board[i][j];
        board[i][j]='*';
        dfs(board,i+1,j,root->get(ch),s);
        dfs(board,i-1,j,root->get(ch),s);
        dfs(board,i,j+1,root->get(ch),s);
        dfs(board,i,j-1,root->get(ch),s);
        board[i][j]=ch;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<words.size();i++)
        {
            trie.insert(words[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dfs(board,i,j,trie.root, "");
            }
        }
        return ans;
    }
};