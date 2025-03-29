class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                q.push({0,{i,j}});
                vis[i][j]=1;
                }
                else
                {
                    vis[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            int d=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
             dis[row][col]=d;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
                {
                    q.push({d+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                    
                }
            }
        }
        return dis;
    }
};