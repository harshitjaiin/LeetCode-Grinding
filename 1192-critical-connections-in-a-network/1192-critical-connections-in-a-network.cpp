class Solution {
public:
    int timer = 1;
    void dfs(int node , int parent ,int inTime[] , int low[] , vector<int> & visited , vector<vector<int>>& adjList , vector<vector<int>> & ans){

        visited[node]=1;
        inTime[node]=low[node]= timer;
        timer++;
        for(auto it : adjList[node]){
            if(it==parent) continue;
            if(visited[it]==0){
                dfs(it , node ,inTime , low , visited , adjList , ans);
                low[node] = min(low[node] , low[it]);
                //now check ki yeh bridge to ni
                if(low[it]>inTime[node]){
                    ans.push_back({node , it});
                }
            }
            else{
                low[node]=min(low[node] , low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> ans;

        int inTime[n];
        int low[n];
        vector<int> visited(n , 0);

        dfs(0 , -1 , inTime , low , visited , adjList , ans);
        return ans;
    }
};