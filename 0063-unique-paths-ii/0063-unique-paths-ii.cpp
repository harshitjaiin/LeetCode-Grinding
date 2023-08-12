class Solution {
public:
    int solve(int i , int j , int m  , int n ,vector<vector<int>>& grid,vector<vector<int>> & dp){
        if(i==m-1 && j==n-1){
            return 1;
        }

        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        
        //down
         
        int down = 0;
        if(i+1<m && grid[i+1][j]==0){
           down = solve(i+1 , j , m , n ,grid ,dp );
        }
        //right
        int right = 0;
        if(j+1<n && grid[i][j+1]==0){
           right = solve(i , j+1 , m , n ,grid ,dp );;
        }

        return dp[i][j]= down+right;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1) ) ;
        return solve( 0 , 0  , m  , n , grid , dp);
    }
};