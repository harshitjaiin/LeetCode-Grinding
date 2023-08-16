class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0 ; i<32 ; ++i){
            int sum = 0;
            
            for(auto it : nums){
                //har ele ki i times right shift krke last value leke uska sum kr rahe (& 1 means ki jo wo bit hai woi ans aajaye) 
                //&1 ke jagah we can also use (|0) too;
                sum+=(it>>i)&1;
            }
            
            //jo value apne unique ele ki hogi wo hi ek triplet ko kharab kregi toh apan div by 3 krke apne unique number ki bit nikal rahe hai
            sum=sum%3;
            //iske bad apan peeche se nikal rahe islei ans me or krke sum ko left shift krke uski shi jagah pe dal re i means bit position idhar!!    
            ans = ans | sum<<i;
        }
        
        return ans;
    }
};