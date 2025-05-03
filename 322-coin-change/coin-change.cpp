class Solution {
public:
    int solve(vector<int>&coins,vector<vector<int>>&dp,int ind,int target)
    {
        if(ind==0)
        {
             if(target%coins[ind]==0)
             return target/coins[ind];
             else
             return 1e9;
        }
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        int notTake=solve(coins,dp,ind-1,target);
        int take=1e9;
        if(coins[ind]<=target)
        take=1+solve(coins,dp,ind,target-coins[ind]);
        return dp[ind][target]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(coins,dp,n-1,amount);
        if(ans>=1e9)
        return -1;
        return ans;
    }
};