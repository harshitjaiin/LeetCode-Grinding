class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        vector<int> m(26,0);
        int unique = 0;
        unordered_map<string , int > count;

        string temp ="";
        for(int i = 0; i<minSize ; i++){
            temp+=s[i];

            if(m[s[i]-'a']==0) unique++;

            m[s[i]-'a']++;
        }

        if(unique<=maxLetters){
           count[temp]++;
        }

        for(int i = minSize ; i<s.length() ; i++){
            int val = m[temp[0]-'a'];
            if(val==1){
                unique--;
            }

            m[temp[0]-'a']--;
            temp.erase(temp.begin());

            temp+=s[i];

            if(m[s[i]-'a']==0) unique++;

            m[s[i]-'a']++;

            if(unique<=maxLetters){
                count[temp]++;
            }
        }

        int maxi = 0;
        for(auto it : count){
            maxi = max(maxi , it.second);
        }
        return maxi;
    }
};