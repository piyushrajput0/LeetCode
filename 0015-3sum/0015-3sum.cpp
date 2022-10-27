class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            int low=i+1;
            int high=n-1;
            if(i>=1 && nums[i]==nums[i-1])
            {
                continue;
            }
            int sum=nums[i]*-1;
            
            while(low<high)
            {
                // cout<<nums[i]<<" "<<nums[low]<<" "<<nums[high]<<endl;
                
                if(nums[low]+nums[high]==sum)
                {
                    if(s.find({nums[i],nums[low],nums[high]})==s.end())
                    {
                         ans.push_back({nums[i],nums[low],nums[high]});
                        s.insert({nums[i],nums[low],nums[high]});
                    }
                    low++;
                    high--;
                }
                else if((nums[low]+nums[high])<sum)
                {
                    low++;

                }
                else
                {
                    high--;
                }
            }
            
        }
        return ans;
    }
};