#define um unordered_map

class Solution {
public:
    string removeDuplicateLetters(string str) {
        stack<char>s;

        vector<int> m(26 , 0);
        vector<int> vis(26 , 0); 

        for(int i = 0 ;i<str.length() ; i++){
            m[str[i]-'a']++;
        }

        s.push(str[0]);
        m[str[0]-'a']--;
        vis[str[0]-'a']=1;

        for(int i = 1 ; i<str.length() ;i++){
            if(vis[str[i]-'a']!=0){
                m[str[i]-'a']--;
                continue;
            }
            
            while(!s.empty() && str[i]<s.top() && m[s.top()-'a']>0){
                    // m[s.top()]--;
                    vis[s.top()-'a']=0;
                    s.pop();
            }  

                s.push(str[i]);
                vis[str[i]-'a']=1;
                m[str[i]-'a']--;              
            
            }

        string ans = "";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }
};