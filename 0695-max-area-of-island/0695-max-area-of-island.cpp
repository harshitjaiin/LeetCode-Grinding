class Solution {
public:
    int dx[4]={-1 , 1 , 0 , 0};
    int dy[4]={0 , 0 , -1 ,1};
    bool isValid(int i , int j, int n , int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void dfs(int row , int col , vector<vector<int>> & visited , vector<vector<int>> & grid , int  & temp){
        visited[row][col]=1;
        temp++;

        for(int i = 0 ; i<4 ; i++){
            int newR = row + dx[i];
            int newC = col + dy[i];

            if(isValid(newR , newC , grid.size() , grid[0].size()) && visited[newR][newC]==0 && grid[newR][newC]==1){
                dfs(newR , newC , visited , grid , temp);
            }
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n , vector<int>(m , 0));
        
        int ans = 0;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ;j<m ; j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    int temp =0;
                    dfs(i , j , visited , grid , temp);
                    ans = max(temp , ans);
               }
           }
        }
        return ans;

    }
};