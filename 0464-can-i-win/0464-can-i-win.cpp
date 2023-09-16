class Solution {
public:



bool canWin(int maxChoosableInteger, int desiredTotal, int chosen, std::unordered_map<int, bool>& memo) {
    if (desiredTotal <= 0)
        return false;
    
    if (memo.find(chosen) != memo.end())
        return memo[chosen];
    
    for (int i = 1; i <= maxChoosableInteger; ++i) {
        //right shift 1 by this number of times
        //ex 1<<3 -> 0000000100 
        //and ab iska chosen se & lene pe agr 0 aya mtlb chosen me yeh 1 nhi tha
        //in that case we know for sure ki yeh number hamne phele nhi use kia
        int mask = (1 << i);
        if ((chosen & mask) == 0) {
            //yahan pe chosen|mask se basically chosen ke ith bit ko set krre
            //ki aage use na kr paye usko!
            //basically agr tumhare is move ke bad samne wale bande ki call se
            //0 aaye mtlb tum jeet gaye
            if (!canWin(maxChoosableInteger, desiredTotal - i, chosen | mask, memo)) {
               return memo[chosen] = true;
            }
        }
    }
    
    return memo[chosen] = false;
    // return false;
}
bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal <= 0 || desiredTotal < maxChoosableInteger)
        return true;
    int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
    if (sum < desiredTotal)
        return false;
    if (sum == desiredTotal)
        return maxChoosableInteger % 2 == 1;
    
    unordered_map<int, bool> memo;
    return canWin(maxChoosableInteger, desiredTotal, 0, memo);
}
};