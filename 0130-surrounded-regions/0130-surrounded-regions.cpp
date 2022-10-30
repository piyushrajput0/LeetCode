class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        
        queue<vector<int>>border;
        
        int n=board.size();
        int m=board[0].size();
        
vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {
                    if(i==0 || j==0 || i==n-1 || j==m-1)
                    {
                        border.push({i,j});
                        
                    }
                    
                }
            }
        }
        
        
        
        vector<vector<int>>v={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>>q1;
        
        while(!border.empty())
        {
            // cout<<q.size()<<endl;
            vector<int>p=border.front();
            border.pop();
            
            visited[p[0]][p[1]]=1;
            for(int i=0;i<4;i++)
            {
                int x=v[i][0]+p[0];
                int y=v[i][1]+p[1];
                
                if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==0 && board[x][y]=='O')
                {
                    
                    border.push({x,y});
                
                }
            }
            
        }
        
        
          for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && visited[i][j]==0)
                {
                    board[i][j]='X';
                    
                }
            }
        }
        
        
    }
};