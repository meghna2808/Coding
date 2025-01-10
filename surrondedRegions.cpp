class Solution {
public:
    void checkRegion(vector<vector<char>>& board,int i, int j)
    {
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0 || i>=n || j>=m  || board[i][j]!='O') return ;
        board[i][j]='T';
        checkRegion(board,i-1,j);
        checkRegion(board,i+1,j);
        checkRegion(board,i,j-1);
        checkRegion(board,i,j+1);
        // return ;
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
           if(board[i][0]=='O')checkRegion(board,i,0);
           if(board[i][m-1]=='O')checkRegion(board,i,m-1);
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')checkRegion(board,0,j);
            if(board[n-1][j]=='O')checkRegion(board,n-1,j);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='T') board[i][j]='O';

            }
        }
    }
};