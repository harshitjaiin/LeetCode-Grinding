const int inf = 1e7;
class Solution {
    public:
   
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges){
        
        //basic initializations
        vector<int> dis(n , -1);
        vector<pair<int, int>> adj[n + 1];
        for (auto vec : redEdges){
            adj[vec[0]].push_back({vec[1], 1});
        }
        for (auto vec : blueEdges){
            adj[vec[0]].push_back({vec[1], 2});
        }
      
        queue<vector<int>> q;
        // q has -> node , currDistance of this node from 0 , color of the path which we are currently using!
        q.push({0, 0, -1});
        while (q.size() > 0){
            auto currVec = q.front();
            q.pop();
            int currv = currVec[0], distance = currVec[1] ,edgeColor = currVec[2];

            // agar yeh abtk visited nhi hai toh first time visit kr rahe
            // ans since apan bfs krre yehi min dist hogi is node ki
            // toh yeh store karle final ans ie dis me!
            if (dis[currv] == -1){
                dis[currv] = distance;
            }
            
            //ab is node ke sare adj wlo me jaao
            // isme & lagana imp hai warna childPair.first = -1 work hi nhi karega
            // and apan same node bar bar acces krenge aur infinite loop me fas jayenge!!
            for (auto &childPair : adj[currv]){
                int childV = childPair.first, edgeColorOfChild = childPair.second;
                //agr iska child exist krta hai and wo start wala na ho and uska path color current
                // wale path se same na ho toh usko queue me daldo
                // ab iski value ko -1 islie kia coz mai wapas na visit karne lagu isko!!
                if (childV != -1 && (edgeColor == -1 || edgeColor != edgeColorOfChild)){
                    q.push({childV, currVec[1] + 1, edgeColorOfChild});
                    childPair.first = -1;
                }
            }
        }
        return dis;
    }
};
