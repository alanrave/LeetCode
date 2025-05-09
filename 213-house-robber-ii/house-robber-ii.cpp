class Solution {
public:
    int solve(vector<int>temp)
    {
        int n=temp.size();
       int prev=temp[0];
       int prev2=0;
       for(int i=1;i<n;i++)
       {
        int take=temp[i];
        if(i>1)
        take+=prev2;
        int notTake=prev;
        int curi=max(take,notTake);
        prev2=prev;
        prev=curi;
       }
       return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            temp1.push_back(nums[i]);
            if(i!=n-1)
            temp2.push_back(nums[i]);
        }
        return max(solve(temp1),solve(temp2));
    }
};