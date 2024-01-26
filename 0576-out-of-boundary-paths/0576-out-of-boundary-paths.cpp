class Solution {
public:
    int dp[51][51][51];
    const int mod = 1e9+7;
    int solve(int x , int y , int m , int n , int maxMoves){
        if(maxMoves<0) return 0;
        if(x<0 || y<0 || x>=m || y>=n) return 1;
        
        if(dp[x][y][maxMoves]!=-1) return dp[x][y][maxMoves];
        
        int right = solve(x , y+1 , m  , n, maxMoves-1)%mod;
        int left  = solve(x , y-1 , m  , n, maxMoves-1)%mod;
        int up    = solve(x-1 , y , m  , n, maxMoves-1)%mod;
        int down  = solve(x+1 , y , m  , n, maxMoves-1)%mod; 

        return dp[x][y][maxMoves]=((((right+left)%mod+up)%mod+down)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp , -1 , sizeof dp);
        return solve( startRow , startColumn , m , n  ,maxMove);
    }
};