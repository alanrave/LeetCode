class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int l=0;int h=n-1;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
        
                swap(matrix[i][j],matrix[j][i]);
               
            }
        }
       /* for(int i=0;i<n;i++)
        {
            l=0;
            h=n-1;
            for(int j=0;j<n;j++)
            {
                if(l<=h)
                {
                    swap(matrix[i][l],matrix[i][h]);
                    l++;
                    h--;
                }
            }
        }*/
        for(int i=0;i<n;i++)
       reverse(matrix[i].begin(),matrix[i].end());
    }
};