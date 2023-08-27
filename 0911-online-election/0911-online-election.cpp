class TopVotedCandidate {
public:
    unordered_map<int ,int> lead;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        int leader = -1;
        unordered_map<int , int> count;
        for(int i = 0 ; i<persons.size() ; i++){
            count[persons[i]]++;
            //basically ab ye banda lead karega
            if(leader==-1 || count[persons[i]]>=count[leader]){
               leader=persons[i];
            }
            //update leader for this particular time!
            lead[times[i]]=leader;
        }
    }
    
    int q(int t) {
        //upper bound jo bhi hoga usse ek kam 
        return lead[*--upper_bound(times.begin() , times.end() , t)];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */