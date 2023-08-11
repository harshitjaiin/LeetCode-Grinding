class Solution {
public:
    // simple greedy soln
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        if(n==0) return 1;
        if(flowerbed.size()==1){
            return (flowerbed[0]==0 && n==1) ? 1 :0;
        }
        for(int i = 0 ; i<flowerbed.size()-1 ; i++){
            if(flowerbed[i]==1){
               i++;
            }
            else if(flowerbed[i+1]==0){
                count++;
                flowerbed[i]=1;
                i++;
                if(count==n){
                    return 1;
                }
            }
        }
        if(flowerbed[flowerbed.size()-1]==0 && flowerbed[flowerbed.size()-2]==0){
            count++;
        }
        if(count>=n){
            return 1;
        }
        return 0;
    }
};