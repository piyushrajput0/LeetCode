class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int currbuy=0;
        int currsell=0;
        
        int n=prices.size();
        for(int i=n-1;i>=0;i--)
        {
            int buy=max(currbuy,currsell-prices[i]);
            int sell=max(currsell,currbuy+prices[i]);
            
           currbuy=buy;
            currsell=sell;
        }
        
        return currbuy;
    }
        
};