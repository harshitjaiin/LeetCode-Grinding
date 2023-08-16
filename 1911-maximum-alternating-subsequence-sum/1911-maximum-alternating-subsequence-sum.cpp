class Solution {
public:
    long long solve(vector<int> & nums ,int index , bool isEven , vector<vector<long long>> & dp){
        if(index>=nums.size()) return 0;

        if(dp[index][isEven]!=-1) return dp[index][isEven];

        //case1 skip
        long long skip = solve(nums , index+1 , isEven ,dp);
        
        long long notSkip ;
        if(isEven)
           notSkip = nums[index]+solve(nums , index+1 , !isEven ,dp);

        else
           notSkip = -nums[index]+solve(nums , index+1 , !isEven , dp);
        
        return dp[index][isEven]=max(skip, notSkip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        //agr tune x ele select kie toh put at even places!
        //even is 1 and odd is 0
        vector<vector<long long>> dp(nums.size()+1 , vector<long long>(2 , -1));
        return solve(nums, 0 , 1 , dp);
    }
};