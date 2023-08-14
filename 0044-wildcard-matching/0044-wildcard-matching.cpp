class Solution {
public:
    bool solve( string & text, string & pattern , int i , int j , vector<vector<int>> & dp){
        if(i==text.length()){
           while(j<pattern.length()){
               if(pattern[j]!='*'){
                   return dp[i][j]=0;
               }
               j++;
           }
           return dp[i][j]=1;
        }
        if(j==pattern.length()){
            return dp[i][j]= 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(text[i]==pattern[j]){
            return dp[i][j]= solve(text , pattern ,i+1 , j+1 , dp);
        }
        else{
            if(pattern[j]=='?'){
                return dp[i][j]= solve(text , pattern , i+1 , j+1 ,dp);
            }
            else if(pattern[j]=='*'){
                return  dp[i][j]= solve(text , pattern , i , j+1 , dp) || solve(text , pattern , i+1 , j , dp); 
            }
            else{
                return dp[i][j]=0;
            }
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp( s.length()+1 , vector<int> ( p.length()+1 , -1));
        return solve( s , p , 0 , 0  , dp);
    }
};