#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0;
        int r=0;
        map<char,int>mpp;
        int maxLen=INT_MIN;
        if(n==0)
        return 0;
        while(r<n)
        {
          char c=s[r];
          if(mpp.find(c)!=mpp.end()&&mpp[c]>=l)
          {
            
            l=mpp[c]+1;
            mpp[c]=r;
          }
          else
          mpp[c]=r;
          maxLen=max(maxLen,r-l+1);
          r++;
        }
        return maxLen;
    }
};