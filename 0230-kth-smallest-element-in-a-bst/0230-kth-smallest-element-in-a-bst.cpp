/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderTraversal(TreeNode *root, int k ,vector<int>&inorder)
    {
        if(root==NULL)
        return;
        inorderTraversal(root->left,k,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,k, inorder);

    }
    int findkthsmallest(vector<int>inorder,int k)
    {
        int size=inorder.size();
        int cnt=0;
        for(int i=0;i<size;i++)
        {
            cnt++;
            if(cnt==k)
            {
                return inorder[i];
            }
        }
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
        return -1;
        vector<int>inorder;
        inorderTraversal(root,k,inorder);
        int res=findkthsmallest(inorder,k);
        return res;
    }
};