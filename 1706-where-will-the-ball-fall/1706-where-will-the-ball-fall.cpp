class Solution {
public:
   int dfs(int row, int col, vector<vector<int>>& grid) {
        // base case; ball reached the last row
        if (row == grid.size()) return col;

        //read editorial for better understanding!
        int nextColumn = col + grid[row][col];
        if (nextColumn < 0 || nextColumn >= grid[0].size()
                                || grid[row][col] != grid[row][nextColumn]) {
            return -1;
        }
        return dfs(row + 1, nextColumn, grid);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int balls =  grid[0].size();
        vector<int> ans(balls,0);
        for(int i = 0 ; i<balls ; i++){
            ans[i] = dfs( 0 , i ,grid );
        }
        return ans;
    }
};

