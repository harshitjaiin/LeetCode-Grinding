class Solution {
public:
    char genes[4]={'A' , 'C' ,'G' ,'T'};
    int minMutation(string startGene, string endGene, vector<string>& BankValues) {
        unordered_set<string> bank(BankValues.begin() , BankValues.end());

        if(bank.find(endGene)==bank.end()){
            return -1;
        }

        queue<pair<int , string>>q;
        q.push({0 , startGene});
        bank.erase(startGene);

        while(!q.empty()){
            int val = q.front().first;
            string node = q.front().second;
            q.pop();

            if(node==endGene){
                return val;
            }

            for(int i = 0 ; i<node.length() ; i++){
                char original = node[i];
                for(int j = 0 ; j<4 ; j++){
                    node[i]=genes[j];
                    if(bank.find(node)!=bank.end()){
                        q.push({val+1 , node});
                    }
                }
                node[i]=original;
                bank.erase(node);
            }
        }
        return -1;
    }
};