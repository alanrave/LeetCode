class Solution {
public:
    void count_digits(int num,vector<int>&count)
    {
        int n=num;
        int c=0;
        while(n!=0)
        {
            n=n/10;
            c++;
        }
        if(c%2==0)
        count.push_back(num);
    }
    bool check_sym(int num)
    {
         string n=to_string(num);
        int s=n.size()/2;
        string nm=n;
        reverse(nm.begin(),nm.end());
        int sum1=0;
        int sum2=0;
        for(int i=0;i<s;i++)
        {
            sum1=sum1+n[i]-'0';
            sum2=sum2+nm[i]-'0';
        }
        return sum1==sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        vector<int>count;
        for(int i=low;i<=high;i++)
        {
            count_digits(i,count);
        }
        int cnt=0;
        for(int i=0;i<count.size();i++)
        {
            if(check_sym(count[i]))
            cnt++;
        }
        return cnt;
    }
};