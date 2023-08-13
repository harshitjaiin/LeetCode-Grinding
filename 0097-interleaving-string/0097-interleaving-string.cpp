class Solution {
public:
    bool solve(string & s1 , string & s2 , string &s3 , int i , int j , int k , vector<vector<int>> & dp){
        
        if(k>=s3.length()){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool case1 = 0;
        if(s1[i]==s3[k]){
            case1 = solve(s1 , s2 , s3 ,i+1 , j , k+1 ,dp);
        }

        bool case2 = 0;
        if(s2[j]==s3[k]){
            case2 = solve(s1 , s2 , s3 , i , j+1 , k+1 ,dp);
        }

        return dp[i][j]=case1||case2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!= s1.length() + s2.length()){
            return 0;
        }
        vector<vector<int>> dp(s1.length()+1 , vector<int>(s2.length()+1 , -1));
        return solve(s1 , s2 , s3, 0 , 0 , 0 , dp);
    }
};