#define mod 1000000007
class Solution {
public:
    int solve(int prev,int count,int &n,vector<vector<int>>&dp)
    {
        if(count==n) return 1;

        if(dp[count][prev]!=-1) return dp[count][prev]%mod;

        int ans=0;
        //try all options here!
        for(int i=1;i<=5;i++)
        {
            if(prev==1 && i==2) //If previous taken is a
                ans=(ans%mod+solve(i,count+1,n,dp)%mod)%mod;

            else if(prev==2 && (i==1 || i==3)) //If previous is e
                ans=(ans%mod+solve(i,count+1,n,dp)%mod)%mod;

            else if(prev==3 && i!=3) //If previous taken is i
                ans=(ans%mod+solve(i,count+1,n,dp)%mod)%mod;

            else if(prev==4 && (i==3 || i==5)) //If previous taken is o
                ans=(ans%mod+solve(i,count+1,n,dp)%mod)%mod;

            else if(prev==5 && i==1) //If previous taken is u.
                ans=(ans%mod+solve(i,count+1,n,dp)%mod)%mod;
        }

        return dp[count][prev]=ans%mod; 
    }
    int countVowelPermutation(int n) {
        
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(6,-1)); 
        for(int i=1;i<=5;i++){
           ans= (ans%mod + solve(i,1,n,dp)%mod)%mod; 
        }
        
        return ans%mod; // return ans;
    }
};