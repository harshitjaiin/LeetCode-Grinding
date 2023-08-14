//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[] , int start , int end , vector<vector<int>> & dp){
        if(start>=end) return 0;
        
        if(dp[start][end]!=-1) return dp[start][end];
        int cost = INT_MAX;
        
        for(int i = start ; i<end ; i++){
            cost = min(cost , solve(arr , start , i ,dp) + solve(arr , i+1 , end ,dp) + arr[start-1]*arr[i]*arr[end]);
        }
        return dp[start][end]=cost;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N+1 , vector<int>(N+1 , -1));
        return solve(arr , 1 , N-1 ,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends