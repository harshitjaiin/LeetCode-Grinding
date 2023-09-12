class Solution {
public:
    int solve(int row , int prevCol , vector<vector<int>> & grid , vector<vector<int>> & dp){
        if(row==grid.size()){
            return 0;
        }

        if(dp[row][prevCol]!=-1) return dp[row][prevCol];

        int ans = INT_MAX;
        for(int i = 0 ; i<grid[0].size() ; i++){
            if(i!=prevCol){
                ans = min(ans , grid[row][i]+solve(row+1 , i , grid , dp));
            }
        }
        return dp[row][prevCol]= ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));
        for(int i = 0 ; i<n ; i++){
            ans = min(ans , grid[0][i]+ solve(1 , i , grid , dp));
        }
        return ans;
    }
};