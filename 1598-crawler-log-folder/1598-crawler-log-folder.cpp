class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(int i = 0;i<logs.size();i++)
        {
            if(logs[i]=="../" && ans>0) ans-=1;
            else if(logs[i]!="../" && logs[i]!="./") ans+=1;
        }
        return ans;
    }
};