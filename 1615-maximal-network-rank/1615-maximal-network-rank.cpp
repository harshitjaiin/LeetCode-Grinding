class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       vector<int> ranks(n ,  0);

       vector<vector<int>> adjList(n);
       
       
       for(auto it : roads){
           adjList[it[0]].push_back(it[1]);
           adjList[it[1]].push_back(it[0]);
           
           ranks[it[0]]++;
           ranks[it[1]]++;
       }

       int ans = 0;

       for(int i = 0 ; i<n-1 ; i++){
           for(int j =i+1 ; j<n ; j++){
               int total = ranks[i]+ranks[j];
               for(auto it : adjList[i]){
                   if(it==j){
                       total--;
                       break;
                   }
               }

               ans = max(ans , total);
           }
       }
       return ans;
    }
};