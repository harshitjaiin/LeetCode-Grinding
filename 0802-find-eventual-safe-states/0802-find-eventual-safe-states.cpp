class Solution {
public:
    bool dfs(int start , vector<vector<int>> & adjList , vector<int> & visited , vector<int> & pathVisited , vector<int> & ans){
        visited[start]=1;
        pathVisited[start]=1;

        for(auto it : adjList[start]){
            if(visited[it]==0){
                if(dfs(it , adjList , visited , pathVisited , ans)==false){
                    return false;
                }
            }
            else if(pathVisited[it]!=0){
                return false;
            }
        }

        ans[start]=1;
        pathVisited[start]=0;
        return 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adjList) {
        int n = adjList.size();


        vector<int> visited(n , 0);
        vector<int> pathVisited(n , 0);
        vector<int> ans(n , 0);

        for(int i = 0 ; i<n ;i++){
            if(visited[i]==0){
               dfs(i , adjList , visited , pathVisited , ans);
            }
        }

        vector<int> finalans;
        for(int i = 0 ; i<ans.size() ; i++){
            if(ans[i]==1){
                finalans.push_back(i);
            }
        }

        return finalans;
    }
};