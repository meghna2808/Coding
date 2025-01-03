class Solution {
public:
    bool solve(vector<vector<char>>&board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char num='1';num<='9';num++)
                    {
                        if(valid(board,i,j,num))
                        {
                            board[i][j]=num;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                        
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    bool valid(vector<vector<char>>& board , int row, int column, char num)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][column]==num) return false;
            if(board[row][i]==num) return false;
        }
        int startRow=(row/3)*3, startColumn=(column/3)*3;
        for(int i=startRow;i<startRow+3;i++)
        {
            for(int j=startColumn;j<startColumn+3;j++)
            {
                if(board[i][j]==num) return false;
            }
        }
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
        //  return board;
        
    }
};