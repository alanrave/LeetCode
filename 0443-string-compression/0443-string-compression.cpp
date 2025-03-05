class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1)
        {
            return 1;
        }
        int size=chars.size();
        string s;
        char flag=chars[0];
        int cnt=1;
        for(int i=1;i<size;i++)
        {
            if(flag==chars[i])
            {
                cnt++;
            }
            else if(cnt==1)
            {
                s=s+chars[i-1];
                flag=chars[i];
            }
            else 
            {
                s=s+chars[i-1];
                string t=to_string(cnt);
                s=s+t;
                cnt=1;
                flag=chars[i];
            }
        }
        if(cnt==1)
        {
            s=s+chars[size-1];
        }
        else
        {
        s=s+chars[size-1];
        string t=to_string(cnt);
        s=s+t;
        }
        for(int i=0;i<s.size();i++)
        chars[i]=s[i];
        return s.size();
    }
};