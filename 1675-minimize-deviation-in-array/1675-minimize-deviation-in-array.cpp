class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(),nums.end());
        int x = INT_MAX;
        for(auto &it : nums){
            if(it%2!=0){
                it*=2;
            }
            pq.push(it);
            x = min(x , it);
        }

        int ans = INT_MAX , y;
        while(!(pq.top()&1)){
           y = pq.top();
           pq.pop();
           ans = min(ans , abs(y-x));
           pq.push(y/2);
           x = min(x , y/2);
        }
        ans = min(ans , abs(pq.top()-x));
        return ans;

    }
};