class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1, ans = nums[0]; // Store ans = nums[0] for the case when rotated array is same as sorted array
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]>=nums[0])
                start = mid+1;
            else   
            // Update ans if there is an element smaller than nums[0], i.e. there is rotation
                ans = nums[mid], end = mid-1; 
        }
        return ans;
    }
};