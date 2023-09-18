class Solution {
public:
    int countVowelStrings(int n) {
        //pattern recorgize karna h bss!
        //try finding ans for n =1 n =2 and n = 3 and then analyse the results
        vector<int> ans(6 , 1);
        ans[0]=0;
        for(int j = 1 ; j<n ; j++){
        for(int i = 2 ; i<=5 ;i++){
            ans[i]+=ans[i-1];
        }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};