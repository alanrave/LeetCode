/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parents(TreeNode *root,unordered_map<TreeNode *,TreeNode *>&parents_track,TreeNode *target)
    {
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *frontNode=q.front();
            q.pop();
            if(frontNode->left)
            {
                parents_track[frontNode->left]=frontNode;
                q.push(frontNode->left);
            }
            if(frontNode->right)
            {
                parents_track[frontNode->right]=frontNode;
                q.push(frontNode->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode *, TreeNode *>parents_track;
        mark_parents(root,parents_track,target);
        unordered_map<TreeNode *,bool>visited;
        queue<TreeNode *>q;
        q.push(target);
        visited[target]=true;
        int curr_level=0;
        while(!q.empty())
        {
            int size=q.size();
            if(curr_level==k)
            break;
            curr_level++;
            for(int i=0;i<size;i++)
            {
            TreeNode *current=q.front();
            q.pop();

            if(current->left && !visited[current->left])
            {
              q.push(current->left);
              visited[current->left]=true;
            }
            if(current->right && !visited[current->right])
            {
                q.push(current->right);
                visited[current->right]=true;
            }
            if(parents_track[current] && !visited[parents_track[current]])
            {
                q.push(parents_track[current]);
                visited[parents_track[current]]=true;
            }
            }
        }
        vector<int>result;
        while(!q.empty())
        {
            TreeNode *current=q.front();
            result.push_back(current->val);
            q.pop();
        }
        return result;
    }
};