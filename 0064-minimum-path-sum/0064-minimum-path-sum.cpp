class Solution {
public:
    int solve(vector<vector<int>> &grid , int i , int j , int endR , int endC , vector<vector<int>> & dp){
        if(i==endR && j ==endC){
            return grid[i][j];
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int case1  = 1e8;
        //down
        if(i+1<grid.size()){
           case1 = grid[i][j] + solve(grid , i+1 , j , endR , endC ,dp);
        }
        
        int case2 = 1e8;
        //right
        if(j+1<grid[0].size()){
           case2 = grid[i][j] + solve(grid , i , j+1 , endR , endC ,dp);
        }
        
        return dp[i][j] = min(case1 , case2);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , -1));
        return solve(grid , 0 , 0 , n-1 , m-1 ,dp);
    }
};