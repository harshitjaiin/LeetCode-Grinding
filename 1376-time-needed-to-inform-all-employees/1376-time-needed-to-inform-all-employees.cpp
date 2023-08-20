class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0 ;
        queue<pair<int , int>> q;
        // q->node , time
        vector<vector<int>> adjList(n);

        for(int i = 0 ; i<n ; i++){
            if(manager[i]!=-1)
             adjList[manager[i]].push_back(i);
        }
        q.push({headID , informTime[headID]});
        cout<<"HI"<<endl;

        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0 ; i<size ; i++){

            pair<int , int> temp = q.front();
            q.pop();
            
            int node = temp.first;
            int time = temp.second;
            
            ans = max(ans ,  time);

            for(auto it : adjList[node]){
                q.push({it , time+informTime[it]});
            }

            }
        }
        return ans;
    }
};