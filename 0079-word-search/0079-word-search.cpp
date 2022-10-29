class Solution {
public:
    int flag=0;
    vector<vector<int>>v={{0,1},{1,0},{0,-1},{-1,0}};
    void help(int x,int y,vector<vector<char>>&board,vector<vector<int>>&visited,int idx,string  &word)
    {
        if(idx==word.size())
        {
            flag=1;
            return ;
        }
        visited[x][y]=1;
        
        for(int i=0;i<4;i++)
        {
            
            int xx=x+v[i][0];
            int yy=y+v[i][1];
            
            if(xx>=0 && yy>=0 && xx<board.size() && yy<board[0].size() && visited[xx][yy]==0 && board[xx][yy]==word[idx])
            {
                // cout<<word[idx]<<endl;
                
                help(xx,yy,board,visited,idx+1,word);
            }
            
        }
        visited[x][y]=0;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[0]==board[i][j])
                 { //int flag=0;
                vector<vector<int>>visited(n,vector<int>(m,0));
                help(i,j,board,visited,1,word);
                if(flag)
                {
                    return true;
                }
                }
            }
        }
        return false;
    }
};