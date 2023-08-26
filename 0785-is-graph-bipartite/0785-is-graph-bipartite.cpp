class Solution {
public:
    bool dfs(vector<vector<int>> & adjList , int start , vector<int> & color , bool toColor){
        color[start]=toColor;

        for(auto it : adjList[start]){
            if(color[it]==-1){
                if(dfs(adjList , it , color , !toColor)==false){
                    return false;
                }
            }
            else if(color[it]==toColor){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjList(n);

        for(int i = 0 ; i<n ; i++){
            for(auto it : graph[i]){
                adjList[i].push_back(it);
            }
        }

        vector<int> color (n , -1);

        for(int i = 0 ; i< n ; i++){
            if(color[i]==-1){
                if(dfs(adjList , i , color , 0 )==false){
                    return 0;
                }
            }
        }
        return 1;
    }
};