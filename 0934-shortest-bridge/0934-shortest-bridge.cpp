class Solution
{
public:
    int del_r[4] = {-1, 1, 0, 0};
    int del_c[4] = {0, 0, -1, 1};

    void dfs(int row, int col, vector<vector<int>> &visited , vector<vector<int>> & grid , queue<vector<int>> & q)
    {
        visited[row][col] = 1;
        grid[row][col] = 2;
        q.push({row , col , 0});
        cout<<row<<" "<<col<<endl;

        for (int i = 0; i < 4; i++)
        {
            int newR = row + del_r[i];
            int newC = col + del_c[i];

            if (newR >= 0 && newC >= 0 && newR < visited.size() && newC < visited.size() && grid[newR][newC]==1)
            {
                dfs(newR, newC, visited , grid , q);
            }
        }
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        queue<vector<int>> q;

        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        bool flag = 0;
        for (int i = 0; i <n && flag==0; i++)
        {
            for (int j = 0; j <n && flag==0; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {   
                    dfs(i, j, visited , grid, q);
                    flag = 1;
                }
            }
        }

        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();
            int row = temp[0];
            int col = temp[1];
            int val = temp[2];
        
            for(int i = 0 ; i<4 ; i++){
                int newR = row + del_r[i];
                int newC = col + del_c[i];

                if(newR>=0 && newC>=0 && newC<n && newR<n){
                    if(grid[newR][newC]==2) continue;
                    if(grid[newR][newC]==1){
                        return val;
                    }

                    grid[newR][newC]=2;
                    q.push({newR , newC , val+1});
                }
            }
        }
        return 0;
    }
};