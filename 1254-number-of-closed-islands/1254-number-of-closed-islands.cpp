class Solution {
public:
    int dx[4]={-1 , 1 , 0 , 0};
    int dy[4]={0 , 0 , -1 ,1};
    bool isValid(int i , int j, int n , int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void dfs(int row , int col , vector<vector<int>> & visited , vector<vector<int>> & grid){
        visited[row][col]=1;
        cout<<row<<","<<col<<endl;
        for(int i = 0 ; i<4 ; i++){
            int newR = row + dx[i];
            int newC = col + dy[i];

            if(isValid(newR , newC , grid.size() , grid[0].size()) && visited[newR][newC]==0 && grid[newR][newC]==0){
                dfs(newR , newC , visited , grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n , vector<int>(m , 0));

        //1st row
        for(int i = 0 ;i<m ; i++){
            if(visited[0][i]==0 && grid[0][i]==0){
                dfs(0 , i , grid , visited);
            }
        }
        //1st col
        for(int i = 0 ;i<n ; i++){
            if(visited[i][0]==0 && grid[i][0]==0){
                dfs(i , 0 , grid , visited);
            }
        }
        //last row
        for(int i = 0 ;i<m ; i++){
            if(visited[n-1][i]==0 && grid[n-1][i]==0){
                dfs(n-1 , i , grid , visited);
            }
        }
        //last col
        for(int i = 0 ;i<n; i++){
            if(visited[i][m-1]==0 && grid[i][m-1]==0){
                dfs(i , m-1 , grid , visited);
            }
        }
        
        int ans = 0;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ;j<m ; j++){
                if(visited[i][j]==0 && grid[i][j]==0){
                    ans++;
                    dfs(i , j , visited , grid);
               }
           }
        }
        return ans;

    }
};