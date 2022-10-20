class Solution {
public:
    bool isMatch(string s, string p) {
        
        
        int n=p.size();
        int m=s.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=1;   
                }
                else if(i==0)
                {
                    dp[i][j]=false;
                }
                else if(j==0)
                {
                    if(p[i-1]=='*')
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
                else
                {
                    if(s[j-1]==p[i-1] || p[i-1]=='?')
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[i-1]=='*')
                    {
                        dp[i][j]=dp[i-1][j] || dp[i][j-1];
                    }
                }
            }
        }
        
       // for(int i=0;i<=n;i++)
       // {
       //     for(int j=0;j<=m;j++)
       //     {
       //         cout<<dp[i][j]<<" ";
       //     }
       //     cout<<endl;
       // }
        return dp[n][m];
        
        
        
    }
};
