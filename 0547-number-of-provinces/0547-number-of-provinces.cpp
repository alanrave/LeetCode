#include<bits/stdc++.h>
using namespace std;
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
        int n=isConnected.size();
        int cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
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