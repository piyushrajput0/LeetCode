class Solution {
public:
    string longestPalindrome(string s) {
    
        int n=s.size();
        string str="";
        vector<vector<int>>dp(n,vector<int>(n,0));
        int ans=0;
        for(int gap=0;gap<n;gap++)
        {
            int j=gap;
            for(int i=0;i<n && j<n;i++,j++)
            {
                if(i==j)
                {
                    dp[i][j]=1;
                    ans=1;
                    str=s[i];
                }
                else if(gap==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=1;
                        if(ans<j-i+1)
                        {
                            str=s.substr(i,j-i+1);
                            ans=j-i+1;
                        }
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1])
                    {
                        dp[i][j]=dp[i+1][j-1];
                        if(ans<(j-i+1))
                        {
                            cout<<i<<" "<<j<<" "<<n<<endl;
                            str=s.substr(i,j-i+1);
                            ans=j-i+1;
                        }
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
            }
        }
        
        
        return str;
    }
};