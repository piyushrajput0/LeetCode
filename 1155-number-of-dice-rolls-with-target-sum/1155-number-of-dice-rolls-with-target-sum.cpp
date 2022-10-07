class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        
        int mod=1e9+7;
        int dp[n+1][target+1];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=k && i<=target;i++)
        {
            dp[1][i]=1;
        }
        for(int i=2;i<=n;i++)
        {
            dp[i][i]=1;
            for(int j=i+1;j<=target;j++)
            {
                
                for(int p=1;p<=k;p++)
                {
                    if(j-p<0)
                    {
                        break;
                    }
                    else
                    {
                        dp[i][j]=(dp[i][j]+(dp[i-1][j-p]%mod))%mod;
                    }
                    
                }
                
            }
        }
        
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=target;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
     
        return dp[n][target];
    }
};