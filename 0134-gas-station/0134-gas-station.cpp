class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start=0;
        int need=0;
        int gass=0;
        
        for(int i=0;i<gas.size();i++)
        {
            gass+=gas[i]-cost[i];
            if(gass<0)
            {
                start=i+1;
                need+=-gass;
                gass=0;
                
            }
        }
        return gass>=need?start:-1;
    }
};