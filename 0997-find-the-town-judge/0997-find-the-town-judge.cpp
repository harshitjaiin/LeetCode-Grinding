class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustBySome(n+1,0);
        vector<int> trustsSome1(n+1,0);
        
        for(auto it : trust){
           int u = it[0];
           int v = it[1];

           trustsSome1[u]++;
           trustBySome[v]++;
        }

        for(int i = 1;i<n+1 ; i++){
            if(trustsSome1[i]==0 && trustBySome[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};