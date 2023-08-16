class Solution {
public:
    bool findSubarraySumtoK(vector<int> & nums, int index , int K , vector<vector<int>> & dp){
        if(index>=nums.size()){
            return K==0;
        }

        if(K==0) return 1;

        if(dp[index][K]!=-1) return dp[index][K];

        //unpick
        bool case1 = findSubarraySumtoK(nums, index+1 , K , dp);

        //pick
        bool case2 = 0;
        if(K>=nums[index])
          case2 = findSubarraySumtoK(nums , index+1 , K - nums[index] ,dp);

        return dp[index][K]=case1||case2;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        
        if(sum%2!=0) return 0;
        else{
            vector<vector<int>>dp(nums.size() , vector<int>(sum/2+1 , -1));
            return findSubarraySumtoK(nums , 0 , sum/2 ,dp);
        }
    }
};