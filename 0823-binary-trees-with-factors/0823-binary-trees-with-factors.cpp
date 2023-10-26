class Solution {
public:
    unordered_map<int , int> m;

    bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }

    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

//prime ke lie ek hi option hai aur baki sb usi se derive hojega
// do dry run for [2 , 4, 5, 10] and you'll def understand all of it!
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin() ,arr.end());
        int n = arr.size();
        for(int i = 0 ; i<n ;i++){
            m[arr[i]]=i;
        }
        vector<long long int> ans(n , 1);
        for(int i = 0 ; i<n ; i++){
            if(!is_prime(arr[i])){
                for(int j = 0 ; j<i ; j++){
                    int ele1 = arr[j];
                    int ele2 = arr[i]/ele1;
                    if(arr[i]%arr[j]==0 && m.find(ele2)!=m.end() && m[ele2]<i){
                        ans[i] = ans[i]+(ans[m[ele1]]*ans[m[ele2]]);
                    }
                }
            }
        }
        long long int sum = 0;
        for(auto it : ans){
            sum = (sum + it);
        }
    
        return sum%1000000007;
    }
};