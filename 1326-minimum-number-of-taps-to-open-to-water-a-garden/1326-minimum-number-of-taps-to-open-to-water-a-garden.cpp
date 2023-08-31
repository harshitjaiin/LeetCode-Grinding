class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1 , 1e9);

        dp[0]=0;

        for(int i = 0 ; i<=n ; ++i){
            int start = max(0 , i - ranges[i]);
            int end = min(n , i+ranges[i]);
            //basically is range me agar mai jaau thru this tap
            //mujhe yehi dekhna h ki kya mai abhi dp[j]+1 taps khol 
            //ke aa rahaa hun and kya phele isse kabhi zyada taps khol
            //ke aya hun? if yes then update it to the min val!
            //dp[j]+1 bcz we are assuming dp[j]=0!!
            for(int j = start ; j<=end ; ++j){
                dp[end] = min(dp[end] , dp[j]+1);
            }
        }

        if(dp[n]!=1e9) return dp[n];
        return -1;
    }
};