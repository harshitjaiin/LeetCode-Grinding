class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int slow = nums[0];
      int fast = nums[0];
      do{
        //1 step to slow
        slow = nums[slow];

        //2 step to fast
        fast = nums[fast];
        fast = nums[fast];
      }
      while(slow!=fast);
      
      //equal aaye toh ab ek ho head pe lejao firse
      fast = nums[0];
      while(slow!=fast){
        //ab dono ko 1 1 step do
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;
    }
};