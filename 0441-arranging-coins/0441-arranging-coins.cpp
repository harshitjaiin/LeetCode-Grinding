class Solution {
public:
    int arrangeCoins(int n) {
        int level = 1;
        int coins = n;

        while(coins!=0){
          if(coins-level>0){ 
            coins-=level;
            level++;
          }
          //agr ye lvl pura kha gaya toh yehi ans!
          else if(coins==level){
            return level;
          }
          //agr ye level pura ni kha payega toh iske phele wala level ans!
          else if(coins<level){
            return level-1;
          }
        }
        return level-1;
    }
};