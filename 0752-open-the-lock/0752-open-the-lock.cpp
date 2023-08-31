class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ends , seen;
        for(auto it : deadends){
            ends.insert(it);
        }

        queue<pair<int ,  string>>q;
        q.push({0 ,"0000"});

        while(!q.empty()){
            int steps = q.front().first;
            string node = q.front().second;
            q.pop();

            if(node == target) return steps;

            if(ends.find(node)!=ends.end()) continue;

            for(int i = 0 ; i<4 ; i++){
                
                string temp = node , temp2 = node;
                char og = temp[i];

                int newChar = og - '0' + 1;
                if(newChar == 10) newChar = 0;
                temp[i]= newChar+ '0' ;

                if(ends.find(temp)==ends.end()){
                    if(seen.find(temp)==seen.end())
                    q.push({steps+1 , temp});
                    seen.insert(temp);
                }
                
                int newChar2 = og- '0' - 1;
                if(newChar2 ==-1) newChar2 = 9;
                temp2[i]= newChar2+'0';

                if(ends.find(temp2)==ends.end()){
                    if(seen.find(temp2)==seen.end())
                    q.push({steps+1 , temp2});
                    seen.insert(temp2);
                }

                // temp[i]=og;
            }
            }   
        return -1;
    }
};