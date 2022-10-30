class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int profit=0;
        int mx=0;
        int mn=prices[0];
        for(int i=1;i<n;i++)
        {
            if(mn>=prices[i]  && mx==0)
            {
                mn=prices[i];
            }
            else if(mn<=prices[i] && mx<=prices[i])
            {
                
                    mx=prices[i];
                
                
            }
            else
            {
                profit+=mx-mn;
                
                mn=prices[i];
                mx=0;
            
            }
        }
        if(mx>mn)
        {
            profit+=mx-mn;
        }
        
        return profit;
    }
};