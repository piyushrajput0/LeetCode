class Solution {
public:
    
    bool check(int x,int y, vector<vector<char>>&board)
    {
        vector<int>vertical(10,0);
        vector<int>horizontal(10,0);
        vector<int>cube(10,0);
        
        for(int i=0;i<9;i++)
        {
            if('0'<=board[i][y] && board[i][y]<='9')
            {
                if(vertical[board[i][y]-'0']!=0)
                {
                    return false;
                }
               vertical[board[i][y]-'0']=1;
            }
        }
        
        
        for(int j=0;j<9;j++)
        {
            if('0'<=board[x][j] && board[x][j]<='9')
            {
                if(horizontal[board[x][j]-'0']!=0)
                {
                    return false;
                }
               horizontal[board[x][j]-'0']=1;
            }
        }
        
        int xx=x/3;
        int yy=y/3;
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if('0'<=board[(3*xx)+i][(3*yy)+j] && board[(3*xx)+i][(3*yy)+j]<='9')
                {
                    if(cube[board[(3*xx)+i][(3*yy)+j]-'0']!=0)
                    {
                        return false;
                    }
                   cube[board[(3*xx)+i][(3*yy)+j]-'0']=1;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(!check(i,j,board))
                {
                    return false;
                }
                
            }
        }
        
        return true;
    }
};