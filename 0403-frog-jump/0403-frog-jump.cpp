class Solution {
public:
    unordered_map<int , int> m;
    bool solve(int index , int prev , vector<int> & stones , vector<vector<int>> & dp){
        // if(index>stones.size()) return 0;
        if(index==stones.size()-1) return 1;

        if(dp[index][prev]!=-1) return dp[index][prev];

        bool case1 =0 , case2 = 0 , case3 = 0;

        //case1
        if(prev>1 && m.find(stones[index]+prev-1)!=m.end()){
            case1 = solve(m[stones[index]+prev-1] , prev-1 , stones , dp);
        }

        //case2
        if(m.find(stones[index]+prev)!=m.end()){
            case2 = solve(m[stones[index]+prev] , prev , stones ,dp);
        }

        //case3
        if(m.find(stones[index]+prev+1)!=m.end()){
            case3 = solve(m[stones[index]+prev +1] , prev+1 , stones ,dp);
        }

        return dp[index][prev]=case1||case2||case3;
    }
    bool canCross(vector<int>& stones) {

        if(stones.size()>1){
            if(stones[1]-stones[0]!=1) return 0;
        }
        for(int i = 0 ; i<stones.size() ; i++){
            m[stones[i]]=i;
        }

        vector<vector<int>> dp(2000 , vector<int>(2000 , -1));

        return solve(1 , 1 , stones ,dp);
    }
};