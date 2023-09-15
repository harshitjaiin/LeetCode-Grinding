class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0 , y = 0;
        string dir = "N";

        for(int i = 0 ; i<instructions.size() ; i++){
            if(instructions[i]=='G'){
                if(dir == "N"){
                    y++;
                }
                else if(dir == "S"){
                    y--;
                }
                else if(dir == "E"){
                    x++;
                }
                else{
                    x--;
                }
            }
            else if(instructions[i]=='L'){
                if(dir=="N") dir ="W";
                else if(dir == "W") dir = "S";
                else if(dir == "S") dir = "E";
                else if(dir == "E") dir = "N";
            }
            else{
                if(dir=="N") dir ="E";
                else if(dir == "E") dir = "S";
                else if(dir == "S") dir = "W";
                else if(dir == "W") dir = "N";
            }
        }
        
        //north hi face krra agar abhi bhi toh kabhi circle ni hoga
        //uske alawa har chiz ko agr bhut bar replicate kre toh pakka 
        //wapas ajayega wahin
        return (x==0 && y==0 || dir!="N");
    }
};