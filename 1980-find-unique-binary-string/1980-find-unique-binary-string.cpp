class Solution {
public:
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        //SIMPLE BACKTRIACKING SE BHI HOGA
        //BUT THIS IS SOMETHING NEW!
        //BACKTRACK IS QUES KE NOTES ME HAI!
        unordered_set<int> store;
        for (string num : nums) {
            //1st arguemnt is string jisse conv krna hai
            //2nd arg leave krdo abhi ke lie
            //3rd arg is the type of string (2-> binary , 6->hexa) toh wo us hisab se
            //isko int me convert karega!
            store.insert(stoi(num, 0, 2));
        }

        for(int i = 0 ; i<=n ; i++){
            //agr ye number nhi mila to hogaya yehi ans hai!
            if(store.find(i)==store.end()){
                //another inbuilt fn 
                //bitset wala se int niklegi i ki (but in binary)
                //ab to_string se usko string me convert kie!

                string ans = bitset<16>(i).to_string();
                
                //basically leading zeroes htane the na
                return ans.substr(16-n , n);
            }
        }
        return "";
    }
};