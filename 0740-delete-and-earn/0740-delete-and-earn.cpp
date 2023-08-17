class Solution {
public:

    int f(int ind,vector<int>& sum,vector<int>& dp){ 
        //same memoization funtion int f() of house robber        
        if(ind==0) return sum[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        //agr pick kar rahe mtlb iska toh total jitna sum h wo leleo aur iske just phele
        //wale ka poora skip kardo!!
        int pick=sum[ind]+f(ind-2,sum,dp);

        //else ek peeche ajao bina kch liye!
        int notpick=0+f(ind-1,sum,dp);

        return dp[ind]=max(pick,notpick);
    }
    int deleteAndEarn(vector<int>& nums){
        int n = 10001;
        //sum me basically har value ka total sum likh diye hai apan!
        vector<int> sum(n, 0);
        for(auto num: nums){
            sum[num]+=num;
        }
        vector<int> dp(n, -1);
        int m=sum.size();
        return f(m-1,sum,dp);
    }
};
