class Solution {
public:
    int solve(vector<string> & arr , int index , vector<int> visited){
        if(index>=arr.size()){
            return 0;
        }

        //unpick
        int unpick = solve(arr , index+1 , visited);

        //pick
        int pick = 0;
        bool flag = true;
        for(int i = 0 ; i<arr[index].length() ; i++){
            if(visited[arr[index][i]-'a']==1){
                flag = false;
                // break;
            }
        }
        if(flag){
            unordered_set<int> s;
            //kahi internally hi toh ni repeat ho raha koi charr!
            for(int i = 0 ; i<arr[index].length();i++){
                s.insert(arr[index][i]-'a');
            }
            if(s.size()==arr[index].length()){
            for(int i = 0 ; i<arr[index].length(); i++){
                visited[arr[index][i]-'a']=1;
            }
            pick = arr[index].length() + solve(arr , index+1 , visited);
            }
        }

        return max(pick , unpick);
    }
    int maxLength(vector<string>& arr) {
        vector<int> visited(26 , 0);
        return solve(arr , 0 , visited);
    }
};