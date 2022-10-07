class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        if(n<4)
        {
            return {};
        }
        
        for(int i=0;i<n-3;i++)
        {
            long long int sum=nums[i];
                                                
if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            
            for(int j=i+1;j<n-2;j++)
            {
                sum+=nums[j];
                
              long long int find=target-sum;
                int low=j+1;
                int high=n-1;
                
                while(low<high)
                {
                    if(nums[low]+nums[high]==find)
                    {
                        
                        s.insert({nums[i],nums[j],nums[low],nums[high]});
                         int x=nums[low];
                       while(low<high && nums[low]==x)
                       {
                              low++;
                       }
                        // low++;
                        high--;
                    }
                    else if((nums[low]+nums[high])>find)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
                sum-=nums[j];
            }
            
        }
        
        vector<vector<int>>ans;
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};