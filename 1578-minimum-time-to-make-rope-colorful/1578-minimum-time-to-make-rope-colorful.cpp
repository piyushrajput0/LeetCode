class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
     int ans=0;
        int n=colors.size();
        for(int i=0;i<n;i++)
        {
            if(i!=n-1 && colors[i]==colors[i+1])
            {
                int mx=0;
                int cn=0;
                
                while(i!=n-1 && colors[i]==colors[i+1])
                {
                    ans+=neededTime[i];
                    mx=max(neededTime[i],mx);i++;
                    cn++;
                    
                }
                ans+=neededTime[i];
                    mx=max(neededTime[i],mx);
                
               ans-=mx;
                 
            }
        }
        return ans;
    }
};