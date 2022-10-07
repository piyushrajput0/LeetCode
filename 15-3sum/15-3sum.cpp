class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        vector<vector<int>>finalans;
        sort(nums.begin(),nums.end());
        // set<vector<int>>s;
        for(int i=0;i<nums.size()-2;i++)
        {
            int low=i+1;
            int high=nums.size()-1;
            
            int x=-1*nums[i];
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            
            while(low<high)
            {
              
                // cout<<nums[low]<<" "<<nums[high]<<endl; 
                if((nums[low]+nums[high])==x )
                {
                    
                    
                     finalans.push_back({nums[i],nums[low],nums[high]});
                    int x=nums[low];
                       while(low<high && nums[low]==x)
                       {
                              low++;
                       }
                    
                     
                 
                }
                else if((nums[low]+nums[high])>x)
                {
                    high--;
                }
                else
                {
                    low++;
                }
                
                
                
            
            }
        }
    
        
        return finalans;
    
    }

};


// -4 -1 -1 -1 0 1 2 2

