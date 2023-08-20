class Solution {
public:
    void dfs(int start , vector<vector<pair<int ,int>>> & adjList , vector<int> & visited ,  int & ans ){

        visited[start]=1;

        for(auto it : adjList[start]){
            if(visited[it.first]==-1){

            if(it.second==1){
                ans+=1; 
                // cout<<ans<<endl;
            }

            dfs(it.first , adjList , visited , ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
         
        vector<vector<pair<int , int>>> adjList(n);
        queue<int> q;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adjList[u].push_back({v , 1});
            adjList[v].push_back({u , -1});
        }

        vector<int> visited(n , -1);
        visited[0]=1;
        int ans = 0;

        dfs(0 , adjList , visited , ans );
        
        return ans;

    }
};