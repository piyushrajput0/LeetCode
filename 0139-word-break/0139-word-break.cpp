class Solution {
public:
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
           
           int n=s.size();
        
        vector<int>dp(n+1,0);
        dp[0]=1;
        
        unordered_set<string>present;
    
        for(int i=0;i<wordDict.size();i++)
        {
            present.insert(wordDict[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(present.find(s.substr(j,i-j+1))!=present.end())
                {
                    dp[i+1]=dp[i+1]||dp[j];
                    
                }
            }
        }
        
        return dp[s.size()];
        
        
        
    }
};