class Solution {
public:
    //Bhaisababb Trick kr leta h dfs , bfs mei!!
    //basic math hai sirf
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int width = abs(sx - fx);
        int height = abs(sy - fy);
        //mtlb usi point pe jana hai jaha se start kie yeh chiz bs 1 step ho tabhi
        //possible nhi h kyuki hatna is compulsory
        //but wapas jana is not possible for 1s time!
        if (width == 0 && height == 0 && t == 1) {
            return false;
        }
        return t >= max(width, height);
    }
};