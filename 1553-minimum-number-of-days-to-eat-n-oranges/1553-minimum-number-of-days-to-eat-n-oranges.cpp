class Solution {
public:
    unordered_map<long long,int>dp;
    int minDays(int n) {
        if(n<=1) return n;
        if(dp.count(n)) return dp[n];
        else
            return dp[n]=1+min(n%2+minDays(n/2),n%3+minDays(n/3));
    }
};