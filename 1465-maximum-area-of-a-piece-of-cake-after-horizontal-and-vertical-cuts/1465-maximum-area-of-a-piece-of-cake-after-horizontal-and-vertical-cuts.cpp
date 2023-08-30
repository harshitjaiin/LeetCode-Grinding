class Solution {
public:
    int maxArea(int h, int w, vector<int>& hz, vector<int>& vc){
        hz.push_back(h);
        vc.push_back(w);
        sort(hz.begin() , hz.end());
        sort(vc.begin() , vc.end());
        
        int len = hz[0];
        for(int i = 1 ; i<hz.size() ; i++){  
            len = max( len , hz[i]-hz[i-1]);
        }

        int width = vc[0];
        for(int i = 1 ; i<vc.size() ; i++){
            width = max(width , vc[i]-vc[i-1]);
        }

        return (1LL*len*width)%1000000007;
    }
};