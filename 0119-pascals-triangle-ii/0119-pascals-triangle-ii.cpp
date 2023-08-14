class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        
        vector<int> currRow = {1};
        //pichle wala row ko nikal do
        vector<int> prevRow = getRow(rowIndex-1);
        
        for(int i = 1 ; i<rowIndex ; i++){
            currRow.push_back(prevRow[i-1]+prevRow[i]);
        }
        
        currRow.push_back(1);
        return currRow;
    }
};