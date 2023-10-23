class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int>m;
        m[0]=-1;
        int count = 0 , ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]==0){
                count--;
            }
            else{
                count++;
            }
            if(m.find(count)!=m.end()){
                ans = max(ans , i-m[count]);
            }
            else{
                m[count]=i;
            }
        }
        return ans;
    }
};