class Solution {
public:
    void dfs(int i,vector<vector<int>>&isConnected,vector<int>&vis)
    {
        vis[i]=1;
        for(int j=0;j<isConnected[i].size();j++)
        {
            if(!vis[j]&&isConnected[i][j]==1)
            dfs(j,isConnected,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int>vis (V,0);
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,isConnected,vis);
                cnt++;
            }
        }
        return cnt;
    }
};