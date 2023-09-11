class Solution {
    //LINK TO THE VID - https://www.youtube.com/watch?v=4JF9o6I_KXM
public:
    int minimumSeconds(vector<int>& nums) {
        map<int , int> last , max_time;
        int n = nums.size();
        int ans = n;
        for(int i = 0 ; i<n ; i++){
           nums.push_back(nums[i]);
           last[nums[i]]=-1;
        }

        n = nums.size();

        for(int i = 0 ; i<n ; i++){
            //if this is not our first time meeting this element then we can just take dist b/w them and can
            //calc the time reqd to convert all ele in between to this same one!
            if(last[nums[i]]!=-1){
               int time = (i - last[nums[i]]);
               time = time/2;
               max_time[nums[i]] = max(max_time[nums[i]] , time);
            }
            //THIS MEANS we are storing this first time interaction with this element
            last[nums[i]]=i;
        }
        for(auto&x:max_time)ans = min(ans,x.second);
        
        return ans;
    }
};