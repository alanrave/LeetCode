class Solution {
public:
    void build(int n,int op,int cl,string s,vector<string>&a){
        if(cl==n){
            a.push_back(s);
            return ;
        }
        if(op<n){
            build(n,op+1,cl,s+'(',a);
        }
        if(cl<op){
            build(n,op,cl+1,s+')',a);
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string>a;
       build(n,0,0,"",a);
       return a;
    }
};