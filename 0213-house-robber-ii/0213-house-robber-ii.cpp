class Solution {
public:
    int solve(int index , vector<int> & nums , bool skipFirst , vector<vector<int>> & dp){
        if(index>=nums.size()-1 && skipFirst==0){
            return 0;
        }
        if(index>=nums.size() && skipFirst==1){
            return 0;
        }

        if(dp[skipFirst][index]!=-1) return dp[skipFirst][index];

        //
        int unpick = solve(index+1 , nums , skipFirst , dp);

        int pick = nums[index] + solve(index+2 , nums , skipFirst ,dp);

        return  dp[skipFirst][index] = max(pick , unpick);
    } 
    int rob(vector<int>& nums) {
        //just bhai ek bar 1st wale house ko chdke kam krle
        //ek bar last wale ko chdke
        if(nums.size()==1) return nums[0];
        vector<vector<int>> dp(2 , vector<int>(nums.size()+1 , -1));
        int case1 = solve(0 , nums , 0 , dp);
        int case2 = solve(1 , nums , 1 , dp);
        return max(case1 , case2);
    }
};