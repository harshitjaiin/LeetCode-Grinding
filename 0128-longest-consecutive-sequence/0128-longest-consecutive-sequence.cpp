class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0){
            return 0;
        }
        
        unordered_set<int> m;
        int ans = INT_MIN;
        
        for(auto it : nums){
            m.insert(it);
        }

        for(int i = 0 ; i<nums.size() ; i++){
            if(m.find(nums[i]-1)!=m.end()){
                continue;
            }
            else{
                int x = nums[i];
                int count = 0;
                while(m.find(x)!=m.end()){
                   count++;
                   x++;
                }

                ans = max(ans , count);
            }
        }
        return ans;
    }
};