class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
          sort(intervals.begin(),intervals.end());
          vector<vector<int>> ans;
          int i = 0;

          while( i<intervals.size() ){
              int start = intervals[i][0];
              int end = intervals[i][1];
              
              int j = i+1;
              while(j<intervals.size() && intervals[j][0]<=end){
                  end = max(intervals[j][1] , end);
                  j++;
              }
                ans.push_back({start , end});
                i=j;
            }
          return ans;
    }
};