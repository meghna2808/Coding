class Solution {
public:
    bool check(int i , int j ,vector<vector<char>>& board, int index, string word,vector<vector<bool>>&visited)
    {
        if(index>=word.size()) return true;
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0 ||board[i][j]!=word[index] || visited[i][j]) return false;
            visited[i][j]=true;
            char temp=board[i][j];
            bool up=check(i-1,j,board,index+1,word,visited);
            bool down =check(i+1,j,board, index+1 , word,visited);
            bool left=check(i,j-1,board, index+1,word, visited);
            bool right=check(i,j+1,board,index+1,word,visited);
            if(up || down || left || right ) return true;
            visited[i][j]=false;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                vector<vector<bool>>visited(m ,vector<bool>(n,false));
                if(board[i][j]==word[0])
                {
                   bool checkString= check(i,j,board,0,word,visited);
                   if(checkString) return true;
                }

            }
        }
        return false;
        
    }
};
//change board[i][j]="$" to avoid creating visited;