class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0 ; i<32 ; ++i){
            int sum = 0;
            
            for(auto it : nums){
                sum+=(it>>i)&1;
            }
            
            sum=sum%3;
            
            ans = ans | sum<<i;
        }
        
        return ans;
    }
};