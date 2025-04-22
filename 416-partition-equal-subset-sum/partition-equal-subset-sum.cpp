class Solution {
public:
    bool fun(vector<int>&nums , vector<vector<int>>&dp,int index,int target)
    {
        if(target==0)
        return true;
        if(index==0)
        return (target==nums[0]);
        if(dp[index][target]!=-1)
        return dp[index][target];
        bool notTake=fun(nums,dp,index-1,target);
        bool take=false;
        if(target>=nums[index])
        take=fun(nums,dp,index-1,target-nums[index]);
        return dp[index][target]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
      
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        return false;
        int k=sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return fun(nums,dp,n-1,k);
    }
};