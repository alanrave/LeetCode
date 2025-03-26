class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void bfs(int row, int col, vector<vector<int>>&vis,vector<vector<char>>grid)
    {
      vis[row][col]=1;
      queue<pair<int,int>>q;
      int n=grid.size();
      int m=grid[0].size();
      q.push({row,col});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
      while(!q.empty())
      {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
         for(int i=0;i<4;i++)
         {
                int nrow=delrow[i]+r;
                int ncol=delcol[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
         }
      }
    }
};