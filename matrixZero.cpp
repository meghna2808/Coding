class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int columns=matrix[0].size();
        set<int>s_rows;
        set<int>s_columns;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(matrix[i][j]==0)
                {
                    s_rows.insert(i);
                    s_columns.insert(j);
                }
            }
            
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(s_rows.find(i)!=s_rows.end() || s_columns.find(j)!=s_columns.end())
                {
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};