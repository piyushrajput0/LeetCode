class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        unordered_map<int,int>mp;
            for(int i=0;i<=k && i<n;i++)
            {
                mp[nums[i]]++;
                
                
            }
        
        for(auto x:mp)
        {
            if(x.second>1)
            {
                cout<<x.first<<endl;
                return true;
            }
        }
        int j=0;
        for(int i=k+1;i<n;i++)
        {
            mp[nums[j]]--;
           if(mp[nums[j]]==0)
           {
               mp.erase(nums[j]);
           }
            if(mp.find(nums[i])!=mp.end())
            {
                return true;
            }
            mp[nums[i]]++;
            j++;
        }
        return false;
        
    }
};