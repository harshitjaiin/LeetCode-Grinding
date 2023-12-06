//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    vector<int> topoSort(vector<vector<int>> & adjList , int k){
        vector<int> indegree(k , 0);
        for(int i = 0 ; i<k ; i++){
            for(auto it : adjList[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0 ; i<k ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            for(auto it : adjList[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> adjList(K);
        for(int i = 0 ; i<N-1 ;i++){
            string one = dict[i];
            string two = dict[i+1];
            
            int j = 0 ;
            while(j<min(one.length() , two.length())){
                if(one[j]==two[j]){
                    j++;
                }
                else{
                    adjList[one[j]-'a'].push_back(two[j]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(adjList , K);
        string ans="";
        for(int i = 0 ; i<topo.size() ; i++){
           ans+=(topo[i]+'a');
        }
        return ans;
       }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends