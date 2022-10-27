class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        
        int n=nums.size();
        if(n<2)
        {
            return false;
        }
        else if(n==2)
        {
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=nums[i];
            }
            
            if(sum%k==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        vector<int>prefixsum;
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int x=sum%k; cout<<x<<endl;
            if((i>=1 && x==0) || (mp.find(x)!=mp.end() && (i-mp[x])>=2))
            {
                return true;
            }
           
            
            mp.insert({x,i});
            
        }
        return false;
            
        
        
    }
};