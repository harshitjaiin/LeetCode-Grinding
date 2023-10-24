class Solution {
public:
    void solve(vector<vector<int>> & dp , string & s , string & t , int i , int j , string & ans ){
        if(i==0 && j==0){
            return ;
        }
        if(i==0){
            while(j>0){
                ans.push_back(t[j-1]);
                j--;
            }
            return ;
        }
        if(j==0){
            while(i>0){
                ans.push_back(s[i-1]);
                i--;
            }
            return ;
        }

        if(s[i-1]==t[j-1]){
           ans.push_back(s[i-1]);
           solve(dp , s , t , i-1 , j-1 , ans);
        }
        else{
           if(dp[i-1][j]>dp[i][j-1]){
               ans.push_back(s[i-1]);
               solve(dp , s, t , i-1 , j , ans);
           }
           else{
               ans.push_back(t[j-1]);
               solve(dp , s, t , i , j-1 , ans);
           }
        }
    }

    //lcs nikal do!
    //basically LCS wali table
    //usse jo lcs me bhi tum lete usko 1 hi bar lena
    //aur jo LCS me ni aa raha usko add krte jana accordingly!
    
    string shortestCommonSupersequence(string s, string t) {
        int n = s.length() , m = t.length();
            vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
		    
		    for(int i = 1 ; i<=n ; i++){
		        for(int j = 1 ; j<=m ; j++){
		            if(s[i-1]==t[j-1]){
		                dp[i][j] = 1 + dp[i-1][j-1];
		            }
		            else{
		                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		            }
		        }
		    }
		    
            string ans = "";
            int i = n , j = m;
            while(i>0 && j>0){
                if(s[i-1]==t[j-1]){
                    ans+=(s[i-1]);
                    i--;
                    j--;
                }
                else if(dp[i-1][j]>dp[i][j-1]){
                    ans+=(s[i-1]);
                    i--;
                }
                else{
                    ans+=(t[j-1]);
                    j--;
                }
            }
            while(i>0){
                ans+=s[i-1];
                i--;
            }
            while(j>0){
                ans+=t[j-1];
                j--;
            }
            reverse(ans.begin() , ans.end());
			return ans;
    } 
};