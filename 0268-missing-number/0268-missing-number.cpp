class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N=nums.size();
        int XOR1=0,XOR2=0;
        for(int i=0;i<N;i++)
        {
            XOR1=XOR1^(i);
            XOR2=XOR2^nums[i];
        }
        XOR1=XOR1^N;
        return XOR1^XOR2;
    }
};