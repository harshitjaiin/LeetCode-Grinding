class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        //temp me mai store karunga is point ko base manke
        //isse upar cons kitne 1 hai (agr yeh khud 1 hai toh)
        //wrna toh 0 hi hai!
        vector<vector<int>> temp = matrix;
        int n = matrix.size() , m = matrix[0].size();
        vector<int> consec(m);
        consec = matrix[0];
        for(int i = 1 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(matrix[i][j]==0){
                    temp[i][j]=0;
                    consec[j]=0;
                }
                else{
                    consec[j]++;
                    temp[i][j]=consec[j];
                }
            }
        }
        for(auto & it : temp){
            sort(it.rbegin() , it.rend());
        }

        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                //height toh maine temp pe store kr hi rakhi h
                //cons ones jo tower bana rahe is point se upar top tak
                //wo height agai
               int height = temp[i][j];
               //rev sort kr rakha hai row wise 
               //mtlb ki isse phele wala banda
               //def issey bada hoga
               //mtlb width = j+1;
               int width = j+1;
               ans = max(ans , height*width); 
            }
        }
        return ans;
    }
};