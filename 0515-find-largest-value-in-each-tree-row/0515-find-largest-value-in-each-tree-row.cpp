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
    //BFS soln already in the submissions!
    vector<int> ans;
    void dfs(TreeNode * root , int depth){
        if(root==NULL){
            return;
        }
        //basially first time coming to this depth!
        if(depth==ans.size()){
            ans.push_back(root->val);
        }
        //if already visited then just focus on updation!
        else{
            ans[depth]=max(ans[depth], root->val);
        }

        dfs(root->left , depth+1);
        dfs(root->right , depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        dfs(root , 0);
        return ans;
    }
};