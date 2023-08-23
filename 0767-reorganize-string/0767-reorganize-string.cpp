class Solution {
public:
    
    string reorganizeString(string s) {
      unordered_map<char , int  > freq;

			for(auto it : s){
				freq[it]++;
				int val = freq[it];

				if(s.length()%2==0){
					if(val>=(s.length()/2+1)){
						return "";
					}
				}
				else if(val>(s.length()/2+1)){
					return "";
				}
			}

			string ans = "";

      priority_queue< pair<int , char> > pq;

			for(auto it : freq){
				pq.push({it.second , it.first});
			}

			while(!pq.empty()){
				auto one = pq.top();
				pq.pop();

				if(ans.empty() || ans.back()!=one.second){
           ans+=char(one.second);

					 if(--one.first>0){
						 pq.push(one);
					 }
				}
				else{
					if(pq.empty()){
						return "";
					}

					auto two = pq.top();
					pq.pop();

				  ans+=char(two.second);

					if(--two.first>0){
						pq.push(two);
					}
					pq.push(one);
				}
			}
      
			return ans;
    }
};