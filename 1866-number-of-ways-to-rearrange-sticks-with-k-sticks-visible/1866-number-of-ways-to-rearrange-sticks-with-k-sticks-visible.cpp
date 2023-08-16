int mod = 1000000007;
class Solution {
public:
    long int solve(int n , int k , vector<vector<long int>> & dp){
        if(n==k){
           return 1;
        }
        
        if(n==0 || k==0) return 0;
        
        if(dp[n][k]!=-1) return dp[n][k];
        
        //pure jitne elements hai hmesha ek hi aisa element hoga jo last me rkh do toh wo pakka dikhega!
        //ie the max ele toh uske case me n toh kam hoga hi but k bhi coz wo hmesha dikhega! but agar tum 
        //uske alawa koi aur ele last me rakhte toh pakka ni dikega!! coz usse bada val phele aayega hi na!!
        //toh un cases me sirf n kam hoga k nhi!!
        return dp[n][k] = ( (solve(n-1 , k-1 , dp)%mod) + ((n-1)* (solve(n-1 , k ,dp)%mod)%mod))%mod;
    }
    int rearrangeSticks(int n, int k) {
        
        vector<vector<long int>> dp(n+1 , vector<long int>(k+1 , -1));
        return solve(n, k , dp)%mod;
        
    }
};