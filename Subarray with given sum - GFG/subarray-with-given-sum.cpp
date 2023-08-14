//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> ans;
        
        int start = 0 ;
        long long sum = 0;
        
        for(int end = 0 ; end<n && start<=end; end++){
            sum+=arr[end];
            if(sum==s){
                ans={start+1 , end+1};
                return ans;
            }
            else if(sum>s){
                while(sum>s && start<end){
                    sum-=arr[start];
                    start++;
                }
                if(start>end){
                    return {-1};
                }
                if(sum==s){
                    ans={start+1 , end+1};
                    return ans;
                }
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends