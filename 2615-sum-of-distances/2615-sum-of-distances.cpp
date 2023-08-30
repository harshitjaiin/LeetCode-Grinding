class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map< int , pair<int , long long> > m;
        unordered_map< int , pair<int , long long> > m1;

        vector<pair<int , long long> > temp1;
        vector<pair<int , long long> > temp2;

        for(int i = 0 ;i<nums.size() ; i++){
            int ele = nums[i];
            if(m[ele].first==0){
                m[ele].first = 1;
                m[ele].second = i ;
            }
            else{
                m[ele].first++;
                m[ele].second+=i;
            }

            temp1.push_back({m[ele].first , m[ele].second});
        }

        for(int i = nums.size()-1 ;i>=0 ; i--){
            int ele = nums[i];
            if(m1[ele].first==0){
                m1[ele].first = 1;
                m1[ele].second = i ;
            }
            else{
                m1[ele].first++;
                m1[ele].second+=i;
            }
            temp2.push_back({m1[ele].first , m1[ele].second});
        }

        reverse(temp2.begin() , temp2.end());

        vector<long long> ans(nums.size());

        for(long long i = 0 ; i<nums.size() ; i++){
            int ele = nums[i];
    
                long long elementsFreqFront = temp1[i].first-1;
                long long indexSumFront = temp1[i].second-i;
        
                long long elementsFreqBack = temp2[i].first-1;
                long long indexSumBack  = temp2[i].second-i;

                ans[i] = ((i*elementsFreqFront) - indexSumFront) + (indexSumBack-(elementsFreqBack*i));
        }
        return ans;
    }
};