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
    void parentToNode(TreeNode * temp , vector<vector<int>> & adjList){

        if(temp==NULL) return ;

        if(temp->left){
            adjList[temp->val].push_back(temp->left->val);
            adjList[temp->left->val].push_back(temp->val);
            parentToNode(temp->left , adjList);
        }
        if(temp->right){
            adjList[temp->val].push_back(temp->right->val);
            adjList[temp->right->val].push_back(temp->val);
            parentToNode(temp->right , adjList);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0){
            return {target->val};
        }

        vector<vector<int>> adjList(501);
        // adjList[root].push_back(-1);

        TreeNode * temp = root;
        
        parentToNode(temp , adjList);

        queue<pair<int , int>> q;
        q.push({target->val , -1});

        int level = 0;
        bool flag = false;

        while(!q.empty()){
            int n = q.size();

            if(flag == true){
                vector<int> ans;
                while(!q.empty()){
                    ans.push_back(q.front().first);
                    q.pop();
                }
                return ans;
            }
            while(n--){
                pair<int , int> temp = q.front();
                q.pop();

                int node = temp.first;
                int parent = temp.second;

                for(auto it: adjList[node] ){
                    if(it!=parent)
                     q.push({it , node});
                }

            }
                level++;
                if(level==k){
                    flag = true;
                }
        }
        return {};
    }
};