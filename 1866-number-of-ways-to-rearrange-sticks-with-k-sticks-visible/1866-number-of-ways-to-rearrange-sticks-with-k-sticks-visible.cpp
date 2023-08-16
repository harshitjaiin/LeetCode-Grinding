int mod = 1000000007;
class Solution {
public:
    long int solve(int n , int k , vector<vector<long int>> & dp){
        if(n==k){
           return 1;
        }
        
        if(n==0 || k==0) return 0;
        
        if(dp[n][k]!=-1) return dp[n][k];
        
        return dp[n][k] = ( (solve(n-1 , k-1 , dp)%mod) + ((n-1)* (solve(n-1 , k ,dp)%mod)%mod))%mod;
    }
    int rearrangeSticks(int n, int k) {
        
        vector<vector<long int>> dp(n+1 , vector<long int>(k+1 , -1));
        return solve(n, k , dp)%mod;
        
    }
};