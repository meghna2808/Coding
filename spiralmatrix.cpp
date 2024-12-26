class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int drn=0; // there will be 4 dron 0 is moving toward right
        int left=0, right=matrix[0].size()-1, top=0, bottom=matrix.size()-1;
        vector<int>spiral;
        while(left<=right && top<=bottom)
        {
            if(drn==0)
            {
                for(int i=left;i<=right;i++)
                {
                    spiral.push_back(matrix[top][i]);
                    // cout<<matrix[top][i]<<" ";
                }
                top++;
                drn=1;//downwards
            }
            else if(drn==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    spiral.push_back(matrix[i][right]);
                }
                right--;
                drn=2;// right to left
            }
            else if(drn==2)
            {
                for(int i=right;i>=left;i--)
                {
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--;
                drn=3;// upwards
            }
            else
            {
                for(int i=bottom ;i>=top;i--)
                {
                    spiral.push_back(matrix[i][left]);
                }
                left++;
                drn=0;// towards right;

            }

        }
        return spiral;
        
    }
};