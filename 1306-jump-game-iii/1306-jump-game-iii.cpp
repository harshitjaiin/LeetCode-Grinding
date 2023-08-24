class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n , 0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int x = q.size();

            for(int i = 0 ; i<x ; i++){
                int node = q.front();
                q.pop();
                visited[node]=1;

                if(arr[node]==0) return 1;

                if(node-arr[node]>=0 && !visited[node-arr[node]]){
                    q.push(node-arr[node]);
                }
                if(node+arr[node]<n && !visited[node+arr[node]]){
                    q.push(node+arr[node]);
                }
            }
        }
        return 0;
    }
};