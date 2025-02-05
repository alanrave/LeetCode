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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
        return NULL;

        int n=inorder.size();
        map<int,int> hm;
        for(int i=0;i<n;i++)
        {
            hm[inorder[i]]=i;
        }
        TreeNode *root=new TreeNode ();
        root=buildTreePoIn(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hm);
        return root;
    }
    TreeNode* buildTreePoIn(vector<int>& inorder,int is, int ie, vector<int>& postorder, int ps, int pe, map<int,int> & hm)
    {
        if(ps>pe || is>ie)
        return NULL;
        TreeNode *root =new TreeNode (postorder[pe]);
        int inRoot=hm[root->val];
        int numsLeft=inRoot-is;
        root->left=buildTreePoIn(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,hm);
        root->right=buildTreePoIn(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,hm);
        return root;
    }
};