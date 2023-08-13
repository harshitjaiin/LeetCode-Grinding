class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> visited( n , vector<int> ( m , 0));
        
        for(int i = 0 ; i<m ;i++){
           visited[0][i]=matrix[0][i]-'0';
        }
        for(int i = 0 ; i<n ;i++){
           visited[i][0]=matrix[i][0]-'0';
        }
        
        for(int i = 1 ; i<n ; i++){
            for(int j = 1 ; j<m ;j++){
                if(matrix[i][j]=='1'){
                    visited[i][j]=1+min(visited[i-1][j] , min(visited[i][j-1] , visited[i-1][j-1]));
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i = 0 ; i<n ;i++){
          for(int j =0 ; j<m ;j++){
             ans = max(ans , visited[i][j]);
          }
        }
        return ans*ans;
    }
};