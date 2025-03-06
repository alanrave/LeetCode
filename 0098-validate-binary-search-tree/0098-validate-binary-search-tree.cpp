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
    void inorders(TreeNode *root,vector<int>&inorder)
    {
        if(root==NULL)
        return;
        inorders(root->left,inorder);
        inorder.push_back(root->val);
        inorders(root->right,inorder);

    }
    bool sorted(vector<int>inorder)
    {
        int a=inorder[0];
        for(int i=1;i<inorder.size();i++)
        {
            if(a>inorder[i])
            return false;
            else
            a=inorder[i];
        }
        return true;
    }
    bool allEqual(vector<int>inorder)
    {
       int size=inorder.size();
       map<int,int>mp;
       for(int i=0;i<size;i++)
       {
        mp[inorder[i]]++;
       }
       for(int i=0;i<size;i++)
       {
        if(mp[inorder[i]]>1)
        return false;
        
       }
       return true;
    }
    bool isValidBST(TreeNode* root) {
        vector<int>inorder;
        inorders(root,inorder);
        bool sort=sorted(inorder);
        bool all=allEqual(inorder);
        if(inorder.size()==1)
        return true;
        if(sort && all)
        return true;
        else return false;
    }
};