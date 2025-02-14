class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string ans;
        for(char digit : num)
        {
        while(!st.empty() && k && st.top()>digit)
        {
          st.pop();
          k--;
          if(k==0)
          break;
        }
        st.push(digit);
        }
        while(!st.empty() && k)
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()>0 && ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans=="" ? "0" :ans;
    }
};