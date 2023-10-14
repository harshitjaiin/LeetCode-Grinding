class Solution {
public:
    int solve(int i, vector<int> & cost , vector<int> & time , int remaining , vector<vector<int>> &dp){
        if(remaining<=0) return 0;

        if(i==cost.size()) return 1e9;
        
        if(dp[i][remaining]!=-1) return dp[i][remaining];
        //
        int pick = cost[i]+solve(i+1 , cost , time , remaining-1-time[i] ,dp);

        int unpick = solve(i+1 , cost , time , remaining ,dp);

        return dp[i][remaining]=min(pick , unpick);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size()+1 , vector<int>(cost.size()+1 , -1));
        return solve(0 , cost , time , cost.size() , dp);
    }
};