#include<bits/stdc++.h>
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zeroes=0;
        int l=0;
        int r=0;
        int maxLen=INT_MIN;
        while(r<n)
        {
            if(nums[r]==0)
            zeroes++;
            while(zeroes>k)
            {
                if(nums[l]==0)
                zeroes--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};