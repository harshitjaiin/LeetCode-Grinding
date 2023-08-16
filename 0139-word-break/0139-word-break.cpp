class Solution {
public:
    bool solve(string & s , int index , string temp , unordered_map<string , string> & m , vector<vector<int>> & dp){
        if(index>=s.length()){
            if(temp.empty() || m.find(temp)!=m.end() ){
                return 1;
            }
            return 0;
        }
        int sz = temp.length();
        
        if(dp[index][sz]!=-1) return dp[index][sz];
        
        temp+=s[index];
        
        bool case1 = solve(s ,index+1 , temp , m , dp);
        bool case2 = 0;
        if(m.find(temp)!=m.end()){
            //mil gaya ele toh 2 options h lets continue ya fir yahan break krke aage badho
            
            // temp="";
            case2 = solve(s , index+1 , "" , m , dp);
        }
        
        return dp[index][sz] = case1||case2;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string , string> m;
        vector<vector<int>> dp(s.length()+1 , vector<int>(s.length()+1 , -1));
        for(auto it : wordDict){
           m[it]=it;
        }
        
        string temp ="";
        return solve(s , 0 , temp , m , dp);
    }
};