class Solution {
public:
     bool repeatedSubstringPattern(string str) {
        string doubled = str + str;

        doubled.erase(doubled.begin() + (doubled.size()-1) );
        doubled.erase(doubled.begin());

        return (doubled.find(str) != string :: npos);
    }
};