class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0;
        unordered_map<int , int> m;
        int sum = 0;
        m[0]=1;
        for(int i = 0 ; i<n ;i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0){
                rem+=k;
            }
            //basically is part ka rem agr iske phle bhi aya hua h
            //mtlb uske beech ka part me pura ele ka sum k hi hoga
            //islie ans+=m[rem]
            //ie yeh rem kitne bar aaya abhi wale ke phele!
            if(m.find(rem)!=m.end()){
                ans+=m[rem];
            }
            m[rem]++;
        }
        
        return ans;
    }
};