class Solution {
public:
    int del_r[4]={1 , -1, 0 , 0 };
    int del_c[4]={0 , 0, -1 , 1 };
    int solve(int start , int end , vector<vector<char>> & maze  ){
        queue<vector<int>> q;
        q.push({start , end , 0});

        while(!q.empty()){
            int row = q.front()[0];
            int col = q.front()[1];
            int time = q.front()[2];
            q.pop();
            
            cout<<row<<" "<<col<<" "<<time<<endl;
            if( (row==maze.size()-1 || row==0 || col==0 || col==maze[0].size()-1) && !(row==start && col==end)){
                return time;
            }

            // visited[row][col]=1;

        for(int i = 0 ; i<4 ; i++){
            int newR = row + del_r[i];
            int newC = col + del_c[i];
              
            if( (newR<maze.size() && newR>=0) && (newC>=0 && newC<maze[0].size()) 
                    && (maze[newR][newC]=='.' )){
                    
               //yeh hi ans hai kya??
              if( (row==maze.size()-1 || row==0 || col==0 || col==maze[0].size()-1) && !(row==start && col==end)){
                return time+1;
            }
            maze[newR][newC]='+';
            q.push({newR , newC , time+1});                    
            }
            }
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        if(maze[entrance[0]][entrance[1]]=='+') return -1;
        int n = maze.size() , m = maze[0].size();

        
        return solve( entrance[0] , entrance[1] , maze );
    }
};