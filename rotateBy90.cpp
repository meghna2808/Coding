class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        
        for(int i=0;i<row;i++) O(n^2);
        {
            for(int j=0;j<=i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end()); // takes 0(n) time 
        }
        
    }
};

// time :O(n^2);
//space : O(n)