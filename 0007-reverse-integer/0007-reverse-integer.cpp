class Solution {
public:
    int reverse(int n) {
    long int rev=0;
        while(n!=0)
        {
         int digit=n%10;
         //har step pe check krlo ki bhai bhar toh ni ja raha m is bar
         //mul ya divide krke
            if(rev>(INT_MAX/10)||rev<(INT_MIN/10))
            {
             return 0;
            }
                
         rev=(rev*10)+digit;
            n=n/10;
        }
    
       return rev;
    }
};