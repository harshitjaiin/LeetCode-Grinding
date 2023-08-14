class Solution {
public:
    vector<int> getRow(int numRows) {
        
    
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==0) return {1};
        
        for(int sz = 2 ; sz<=numRows+1 ;sz++){
            
            vector<int> temp(sz , -1);
            temp[0]=1;
            temp[sz-1]=1;

            for(int i = 1 ; i<sz-1 ; i++){
                
               temp[i]=ans[sz-2][i-1] + ans[sz-2][i]; 
                
            }
            
            if(sz==numRows+1){
                return temp;
            }
            // cout<<endl;
            ans.push_back(temp);
            
        }
        return {};
    }
};