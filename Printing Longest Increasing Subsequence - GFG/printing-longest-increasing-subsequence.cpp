//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n , 1) , hash(n , 1);
        for(int i = 0 ; i<n ; i++){
            hash[i]=i;
        }
        
        for(int i = 0 ; i<n ; i++){
            for(int prevInd = 0 ; prevInd<i ; prevInd++){
                if(arr[i]>arr[prevInd]){
                    if(dp[i]<1+dp[prevInd]){
                        hash[i]=prevInd;
                        dp[i]=1+dp[prevInd];
                    }
                }
            }
        }
        vector<int> ans;
        int maxIndex = 0 , maxi = 1;
        for(int i = 0 ; i<n ; i++){
            if(maxi<dp[i]){
                maxi = dp[i];
                maxIndex = i;
            }
        }
        // ans.push_back(arr[maxIndex]);
        while(hash[maxIndex]!=maxIndex){
            ans.push_back(arr[maxIndex]);
            maxIndex = hash[maxIndex];
        }
        ans.push_back(arr[maxIndex]);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends