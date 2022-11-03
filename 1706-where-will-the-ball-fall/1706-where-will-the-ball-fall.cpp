class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        
        vector<int>ans;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int ball=0;ball<m;ball++)
        {
            int i=0;
            int j=ball;
            int flag=true;
            while(true)
            {
                // cout<<i<<" "<<j<<endl;
                if(i>=n)
                {
                    break;
                }
                else if((j<0) || (j>=m) || (grid[i][j]==-1 && j-1==-1) || (grid[i][j]==1 && j+1==m) || (grid[i][j]==1 && grid[i][j+1]==-1) || (grid[i][j]==-1 && grid[i][j-1]==1))
                {
                    flag=false;
                    break;
                }
                else if(grid[i][j]==1)
                {
                    i++;
                    j++;
                }
                else if(grid[i][j]==-1)
                {
                    i++;
                    j--;
                }
            }
            
            if(flag)
            {
                ans.push_back(j);
            }
            else
            {
                ans.push_back(-1);
            }
            
        }
        
        return ans;
    }
};