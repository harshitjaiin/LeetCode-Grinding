int mod = 1e9+7;
class Solution {
public:
    long long  solve(int index , int n , int steps , vector<vector<int>> & dp){
        if(steps==0 && index==0){
            return 1;
        }
        if(steps==0){
            return 0;
        }
        
        if(dp[index][steps]!=-1) return dp[index][steps];

        int moveForward = 0 , stayHere = 0 , moveBack = 0 ;
        if(index+1<n){
            moveForward = solve(index+1 , n , steps-1 ,dp);
        }
        if(index-1>=0){
            moveBack = solve(index-1 , n , steps-1 ,dp);
        }
        stayHere = solve(index , n , steps-1 ,dp);

        return dp[index][steps] = ((moveForward + moveBack)%mod + stayHere)%mod;
    }
    int numWays(int steps, int arrLen) {
        //steps+1 hi tk index jayega use aage ja hi nhi sakta
        //thats why arrlen+1 nhi lia bhuut extra space le raha tha!!
        vector<vector<int>> dp(steps+1 , vector<int>(steps+1 ,-1));
        return solve(0 ,arrLen , steps , dp);
    }
};