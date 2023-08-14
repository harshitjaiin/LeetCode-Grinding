class Solution {
public:
    bool solve(string &input, string &pattern,int i,int j,vector<vector<int>>&dp){
        // base condition
        if(j>=pattern.size())
            return i>=input.size();
        if(i>=input.size()){
            for(int k=j;k<pattern.size();k++){
                if(pattern[k]=='*')continue;
                if(k+1<pattern.size() && pattern[k+1]=='*')continue;
                return 0;
            }
        }
        //check the cache
        if(dp[i][j]!=-1)return dp[i][j];
        //match condition
        if(input[i]==pattern[j] || pattern[j]=='.'){
            if(j+1<pattern.size() && pattern[j+1]=='*')
                return dp[i][j]=
                solve(input,pattern,i,j+2,dp) || solve(input,pattern,i+1,j,dp);
            return dp[i][j]=solve(input,pattern,i+1,j+1,dp);
        }
        //not match condition
        if(j+1<pattern.size() && pattern[j+1]=='*')
                return dp[i][j]=solve(input,pattern,i,j+2,dp);
        return dp[i][j]=0;
        
    }
    bool isMatch(string input, string pattern) {
        int m=pattern.size();
        int n=input.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(input,pattern,0,0,dp);
        
    }
};