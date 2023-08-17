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
    
    vector<TreeNode *> solve( int low , int high ){
         vector<TreeNode * > temp;

         if(low>high){
             temp.push_back(NULL);
             return temp;
         }

         if(low==high){
             temp.push_back(new TreeNode (high));
             return temp;
         }

         for(int i = low ; i<= high ; i++){
             vector<TreeNode *> leftParts = solve(low , i-1);
             vector<TreeNode *> rightParts = solve(i+1 , high);

             for(auto it : leftParts){
                 for(auto itt : rightParts){
                    TreeNode * root = new TreeNode(i);
                    root->left = it;
                    root->right= itt;
                    temp.push_back(root);
                 }
             }
         }
        return temp;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve( 1 , n );
    }
};