class Solution {
public:
    double fun(vector<int>v,int hourly)
    {
        double totalHours=0;
        for(int i=0;i<v.size();i++)
        {
            totalHours+=ceil((double)v[i]/(double)hourly);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=0;
        int n=piles.size();
        int largest=piles[0];
        for(int i=1;i<n;i++)
        {
             if(piles[i]>largest)
             largest=piles[i];
        }
        int high=largest;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(fun(piles,mid)<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};