class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0){
            return nums[0];
        }
        if(n==1 ){
            if(k%2==0) return nums[0];
            else return -1;
        } 
        
        if(k==1){
            if(n>1) return nums[1];
            else return -1;
        }
        
        if(k>n){
            return * max_element(nums.begin() , nums.end());
        }
        if(k==n){
            return *max_element(nums.begin() , nums.begin()+(k-1));
        }
        else{
           return max(*max_element(nums.begin() , nums.begin()+k-1) , nums[k]);
        }
    }
};